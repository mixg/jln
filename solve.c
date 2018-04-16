/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:07:44 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 20:32:48 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		safe(int map_size, int i, char *tet, char *map)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	x = i / map_size;
	y = i % map_size;
	while (*tet)
	{
		if (count == 4)
		{
			x++;
			i = y + x * map_size;
			count = 0;
		}
		if (!(*tet == '.') && !(map[i] == '.'))
			return (0);
		count++;
		i++;
		tet++;
	}
	return (1);
}

void	place(int map_size, int i, char *tet, char **map)
{
	char	*tmp_map;
	int		count;
	int		x;
	int		y;

	tmp_map = *map;
	count = 0;
	x = i / map_size;
	y = i % map_size;
	while (*tet)
	{
		if (count == 4)
		{
			x++;
			i = y + x * map_size;
			count = 0;
		}
		if (*tet != '.' && tmp_map[i] == '.')
			tmp_map[i] = *tet;
		i++;
		tet++;
		count++;
	}
}

int		solve(int map_size, char **tet, char **map)
{
	char	*tmp_map;
	int		map_len;
	int		i;

	map_len = map_size * map_size + map_size;
	tmp_map = *map;
	i = 0;
	if (!*tet)
		return (1);
	while (i < map_len)
	{
		if (safe(map_size + 1, i, *tet, tmp_map))
		{
			place(map_size + 1, i, *tet, &tmp_map);
			if (solve(map_size, tet + 1, &tmp_map))
				return (1);
			else
				remove_block(&tmp_map, *tet);
		}
		i++;
	}
	return (0);
}

int		check_solve(int map_size, char **tet, char **map)
{
	while (!solve(map_size, tet, map))
	{
		free(*map);
		*map = NULL;
		map_size += 1;
		*map = make_map(map_size);
	}
	return (1);
}
