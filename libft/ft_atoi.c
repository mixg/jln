/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:39:17 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/12 17:46:15 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;

	while (*str == '\t' || *str == '\n' || *str == ' ' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	sign = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + ((long)*str++ - '0');
	}
	return (res * sign);
}
