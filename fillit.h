/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:20:13 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/15 00:47:23 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"

# define buf_size 4096

char	*rm_newline(char *s);
char	**tmp_pattern(void);
char	*valid_patterns(int n);
char	*open_read(char *str);
char	**trim_tet(char **tet);
char	**change_char(char **tet);
char	*make_map(int n);
char	letter(char *tet);
int		safe(int map_size, int i, char *tet, char *map);
int		count(char **str);
int		cal_map_size(int n);
int		bool_strstr(const char *haystack, const char *needle);
int		parse_pattern(char **tet);
int		validate(char **tet, char **pattern);
int		check(char **tet);
int		error(int error_value);
int		solve(int map_size, char **tet, char **map);
int		check_solve(int map_size, char **tet, char **map);
void	place(int map_size, int i, char *tet, char **map);
void	remove_block(char **map, char *tet);

#endif
