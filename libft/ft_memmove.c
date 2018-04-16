/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:13:35 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/12 19:46:56 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpsrc;
	unsigned char	*tmpdst;

	tmpsrc = (unsigned char *)src;
	tmpdst = (unsigned char *)dst;
	if (tmpdst <= tmpsrc || tmpsrc >= (tmpdst + len))
	{
		while (len)
		{
			*tmpdst++ = *tmpsrc++;
			len--;
		}
	}
	else
	{
		tmpsrc = tmpsrc + len - 1;
		tmpdst = tmpdst + len - 1;
		while (len)
		{
			*tmpdst-- = *tmpsrc--;
			len--;
		}
	}
	return (dst);
}
