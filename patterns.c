/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:27:35 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 20:34:35 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*valid_patterns(int n)
{
	char	*block_pattern[20];

	block_pattern[0] = "##..#...#";
	block_pattern[1] = "##...#...#";
	block_pattern[2] = "#...#...##";
	block_pattern[3] = ".#...#..##";
	block_pattern[4] = "###.#";
	block_pattern[5] = "###...#";
	block_pattern[6] = "#...###";
	block_pattern[7] = "..#.###";
	block_pattern[8] = "##...##";
	block_pattern[9] = ".#..##..#";
	block_pattern[10] = ".##.##";
	block_pattern[11] = "#...##...#";
	block_pattern[12] = "#...#...#...#";
	block_pattern[13] = "####";
	block_pattern[14] = "##..##";
	block_pattern[15] = ".#..###";
	block_pattern[16] = ".#..##...#";
	block_pattern[17] = "#...##..#";
	block_pattern[18] = "###..#";
	block_pattern[19] = NULL;
	return (block_pattern[n]);
}

char	**tmp_pattern(void)
{
	char	**cpy;
	int		i;

	if (!(cpy = (char **)malloc(20)))
		return (0);
	i = 0;
	while (valid_patterns(i))
	{
		if (!(cpy[i] = (char *)malloc(sizeof(valid_patterns(i)) + 1)))
			return (0);
		cpy[i] = valid_patterns(i);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
