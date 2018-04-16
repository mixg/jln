/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:52:28 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 21:08:50 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(int error_value)
{
	if (error_value)
		ft_putstr("usage: ./fillit <source_file>\n");
	else
		ft_putstr("error\n");
	return (0);
}

int		bool_strstr(const char *haystack, const char *needle)
{
	size_t	nlen;
	size_t	i;
	size_t	j;

	nlen = ft_strlen(needle);
	i = 0;
	if (nlen == 0)
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (j == nlen - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**trim_tet(char **tet)
{
	char	**pattern;
	int		i;
	int		j;

	pattern = tmp_pattern();
	i = 0;
	j = 0;
	while (pattern[j] && tet[i])
	{
		if (bool_strstr(tet[i], pattern[j]))
		{
			tet[i++] = ft_strdup(pattern[j]);
			j = -1;
		}
		j++;
	}
	return (tet);
}

char	**change_char(char **tet)
{
	int	i;
	int	j;

	tet = trim_tet(tet);
	i = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j] && tet[i])
		{
			if (tet[i][j] == '#')
				tet[i][j] += 30 + i;
			j++;
		}
		tet[i++][j] = '\0';
	}
	tet[i] = NULL;
	return (tet);
}
