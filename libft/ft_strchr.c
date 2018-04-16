/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:03:26 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/11 20:50:50 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;
	int		len;

	i = 0;
	s1 = (char *)s;
	len = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&s1[i]);
		i++;
	}
	if (c == '\0')
		return (&s1[len]);
	return (NULL);
}
