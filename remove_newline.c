/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 21:08:15 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 21:10:43 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_newline(char *s)
{
	if (s[4] != '\n')
		return (1);
	while (*s)
	{
		if (*s == '\n' && *(s + 1) == '\n' && *(s + 2) == '\n')
			return (1);
		else if (*s == '\n' && *(s + 1) == '\n' && *(s + 2) == '\0')
			return (1);
		s++;
	}
	return (0);
}

char	*rm_newline(char *s)
{
	char	*str;
	int		i;

	if (find_newline(s))
		return (0);
	i = 0;
	str = s;
	while (*str)
	{
		while (*str == '\n')
		{
			if (*str == '\n' && *(str + 1) == '\n')
				s[i++] = *str++;
			str++;
		}
		while (*str != '\n' && *str)
			s[i++] = *str++;
	}
	s[i] = '\0';
	return (s);
}
