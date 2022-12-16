/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:55:15 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 13:56:19 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memcpy_gnl(char *dst, const char *src, unsigned int n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}
