/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:48:30 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 13:48:57 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str, long *number)
{
	if (ft_atol(str, number))
	{
		if (*number >= INT_MIN && *number <= INT_MAX)
			return (1);
	}
	return (0);
}
