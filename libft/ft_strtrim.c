/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:51:28 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/13 11:45:33 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*fresh;

	if (s == NULL)
		return (0);
	i = -1;
	len = ft_strlen(s);
	while (s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ')
		len--;
	while (s[++i] == '\n' || s[i] == '\t' || s[i] == ' ')
		len--;
	if (len < 0)
		len = 0;
	if (!(fresh = (char *)malloc(len + 1 * sizeof(char))))
		return (0);
	s = s + i;
	i = -1;
	while (++i < len)
		fresh[i] = *s++;
	fresh[i] = '\0';
	return (fresh);
}
