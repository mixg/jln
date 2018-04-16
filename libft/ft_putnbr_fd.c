/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:59:54 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/13 09:43:20 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ncpy;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ncpy = n;
	if (ncpy > 9)
	{
		ft_putnbr_fd(ncpy / 10, fd);
		ft_putnbr_fd(ncpy % 10, fd);
	}
	else
	{
		ncpy += '0';
		ft_putchar_fd(ncpy, fd);
	}
}
