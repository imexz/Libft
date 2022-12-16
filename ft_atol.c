/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:36:06 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 15:28:06 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_whitspace_n_sign(const char *str, int *i, int *sign)
{
	while ((str[*i] >= '\t' && str[*i] <= '\r') || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = (-1);
		(*i)++;
	}
}

int	ft_atol(const char *str, long *number)
{
	int		i;
	long	res;
	int		sign;
	int		digit;

	i = 0;
	res = 0;
	sign = 1;
	digit = 0;
	ft_whitspace_n_sign(str, &i, &sign);
	while (str[i] <= '9' && str[i] >= '0')
	{
		digit++;
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	if (str[i] == '\0' && digit)
	{
		*number = (sign * res);
		return (1);
	}
	return (0);
}
