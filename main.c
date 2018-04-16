/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:24:27 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 20:37:11 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tet;
	char	*map;
	int		map_size;

	if (argc == 1)
		return (error(1));
	if (!(tet = ft_strsplit(open_read(argv[1]), '\n')) || !check(tet))
		return (error(0));
	map_size = cal_map_size(4 * count(tet));
	map = make_map(map_size);
	tet = change_char(tet);
	if (check_solve(map_size, tet, &map))
		ft_putstr(map);
	else
		return (error(0));
	return (0);
}
