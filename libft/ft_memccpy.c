/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:46:10 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/06 15:57:48 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;
	int				i;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		ndst[i] = nsrc[i];
		if (nsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
