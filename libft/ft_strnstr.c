/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 12:38:51 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/27 20:11:22 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *fnd, size_t len)
{
	size_t	nlen;
	size_t	i;
	size_t	j;

	nlen = ft_strlen(fnd);
	if (nlen == 0)
		return ((char *)str);
	i = 0;
	while (str[i] && len)
	{
		j = 0;
		while (str[i + j] == fnd[j] && j < len)
		{
			if (j == nlen - 1)
				return ((char *)str + i);
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}
