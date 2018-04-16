/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:39:43 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 20:40:12 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		cal_map_size(int n)
{
	int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

char	*make_map(int n)
{
	char	*map;
	int		len;
	int		i;
	int		count;

	len = n * n + n;
	if (!(map = (char *)malloc(len + 1)))
		return (0);
	i = -1;
	while (i < len)
	{
		count = -1;
		while (++count <= n && ++i < len)
		{
			if (count == n)
				map[i] = '\n';
			else
				map[i] = '.';
		}
	}
	map[i] = '\0';
	return (map);
}
