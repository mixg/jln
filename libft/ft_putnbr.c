/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:10:55 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/13 09:50:12 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	ncpy;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ncpy = n;
	if (ncpy > 9)
	{
		ft_putnbr(ncpy / 10);
		ft_putnbr(ncpy % 10);
	}
	else
	{
		ncpy += '0';
		ft_putchar(ncpy);
	}
}
