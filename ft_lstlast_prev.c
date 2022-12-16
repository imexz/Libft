/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:09:54 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 15:15:16 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast_prev(t_list *lst)
{
	t_list	*current;
	t_list	*prev;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	return (prev);
}
