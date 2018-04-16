/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:26:32 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/12 19:41:36 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_word(char const *s, char c, int wrdcnt, int wrdlen)
{
	char	**array;
	int		i;
	int		j;
	int		k;

	if (!(array = (char **)malloc(sizeof(*array) * wrdcnt + 1)))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(array[j] = (char *)malloc(sizeof(**array) * wrdlen + 1)))
				return (0);
			while (s[i] != c && s[i])
				array[j][k++] = s[i++];
			array[j++][k] = '\0';
		}
	}
	array[j] = NULL;
	return (array);
}
