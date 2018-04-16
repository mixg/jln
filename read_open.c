/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:41:44 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 00:24:52 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parse_pattern(char **tet)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (tet[i])
	{
		count = 0;
		while ((tet[i][j] == '.' || tet[i][j] == '#') && tet[i][j++])
		{
			if (tet[i] == '#')
				count++;
		}
		if (!(count > 2 && count < 5) || i != 16)
			return (0);
		i++;
	}
	return (1);
}

int		validate(char **tet, char **pattern)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tet[i])
	{
		while (pattern[j])
		{
			if (bool_strstr(tet[i], pattern[j]))
			{
				if (tet[i + 1] == '\0')
					return (1);
				i++;
				j = -1;
			}
			j++;
		}
	}
	return (0);
}

int		check(char **tet)
{
	char	**pattern;

	pattern = tmp_pattern();
	if (validate(tet, pattern) && parse_pattern(tet))
		return (1);
	return (0);
}

char	*open_read(char *str)
{
	int		fd;
	int		i;
	char	buf[buf_size];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		error(0);
		exit(1);
	}
	i = read(fd, buf, buf_size);
	buf[i] = '\0';
	close(fd);
	return (rm_newline(buf));
}
