/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:05:10 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/12 18:01:03 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		ncpy;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	ncpy = n;
	len = 2;
	check_negative(&n, &negative);
	while (ncpy /= 10)
		len++;
	len += negative;
	if ((str = (char *)malloc(len * sizeof(char))) == 0)
		return (0);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
