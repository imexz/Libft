/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:54:16 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/09 13:30:39 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s_line_init(struct s_line *line)
{
	line->alloc = BUFFER_SIZE;
	line->w_head = 0;
	line->chars = malloc(sizeof(char) * line->alloc);
	if (line->chars == NULL)
		return (-1);
	return (0);
}

static char	ft_s_buffer_get_next_char(struct s_buffer *buffer, int fd)
{
	char	c;

	if (buffer->read_head >= buffer->w_head)
	{
		buffer->w_head = read(fd, buffer->buffer, BUFFER_SIZE);
		buffer->read_head = 0;
	}
	if (buffer->w_head == 0)
		return (0);
	else if (buffer->w_head == -1)
		return (-1);
	c = buffer->buffer[buffer->read_head];
	buffer->read_head++;
	return (c);
}

static int	ft_s_line_append_char(struct s_line *line, char c)
{
	unsigned int	new_alloc;
	char			*new_chars;

	if (line->w_head >= line->alloc)
	{
		new_alloc = line->w_head + line->alloc;
		new_chars = malloc(sizeof(char) * new_alloc);
		if (new_chars == NULL)
			return (-1);
		ft_memcpy_gnl(new_chars, line->chars, line->w_head);
		free (line->chars);
		line->chars = new_chars;
		line->alloc = new_alloc;
	}
	line->chars[line->w_head] = c;
	line->w_head++;
	return (0);
}

static char	*ft_s_line_get_str(struct s_line *line)
{
	char	*str;

	if (line->w_head <= 0)
	{
		free(line->chars);
		return (NULL);
	}
	str = malloc(sizeof(char) * line->w_head + 1);
	if (str == NULL)
	{
		free(line->chars);
		return (NULL);
	}
	ft_memcpy_gnl(str, line->chars, line->w_head);
	str[line->w_head] = '\0';
	free (line->chars);
	return (str);
}

char	*get_next_line(int fd)
{
	static struct s_buffer	buffer;
	struct s_line			line;
	char					c;

	if (fd < 0 || (ft_s_line_init(&line) == -1))
		return (NULL);
	while (1)
	{
		c = ft_s_buffer_get_next_char(&buffer, fd);
		if (c == 0)
			break ;
		if (c == -1)
		{
			free (line.chars);
			return (NULL);
		}
		if (ft_s_line_append_char(&line, c) == -1)
		{
			free (line.chars);
			return (NULL);
		}
		if (c == '\n')
			break ;
	}
	return (ft_s_line_get_str(&line));
}
