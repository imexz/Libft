/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:38:15 by mstrantz          #+#    #+#             */
/*   Updated: 2023/02/18 13:46:51 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	ft_count_digits(long n, unsigned int base)
{
	size_t	ret;

	if (n <= 0)
	{
		ret = 1;
		n *= (-1);
	}
	else
		ret = 0;
	while (n > 0)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

// Not Norminette conform. Using "do{...} while(...);"
char	*ft_itoa_base(long n, unsigned int base)
{
	size_t	len;
	char	*str;
	char	*ptr;

	if (base < 2 || base > 16)
		return NULL;
	len = ft_count_digits(n, base);
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return NULL;
	if (n < 0) {
		n *= (-1);
		str[0] = '-';
	}
	ptr = str + len;
	do {
		--ptr;
		*ptr = "0123456789abcdef"[n % base];
		n /= base;
	} while (n != 0);
	return (str);
}

// void test(int x, int base)
// {
// 	char	*str_10;
// 	char	*str_base;

// 	str_10 = ft_itoa_base(x, 10);
// 	str_base = ft_itoa_base(x, base);
// 	printf("%12d: base 10 = %11s, base %2d = %s\n", x, str_10, base, str_base);
// 	free(str_10);
// 	free(str_base);
// }

// int	main(void)
// {
// 	test(123, 16);
// 	test(-123, 16);
// 	test(INT_MIN, 2);
// 	test(0, 2);
// 	test(INT_MAX, 2);
// 	test(INT_MIN, 36);
// 	return 0;
// }
