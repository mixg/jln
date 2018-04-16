/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:26:03 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 00:26:19 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	letter(char *tet)
{
	while (*tet)
	{
		if (ft_isalpha(*tet))
			return (*tet);
		tet++;
	}
	return (0);
}

void	remove_block(char **map, char *tet)
{
	char	c;
	char	*tmp_map;

	c = letter(tet);
	tmp_map = *map;
	while (*tmp_map)
	{
		if (*tmp_map == c)
			*tmp_map = '.';
		tmp_map++;
	}
}
