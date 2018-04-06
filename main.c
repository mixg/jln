/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:24:27 by mxiong            #+#    #+#             */
/*   Updated: 2018/04/06 16:19:50 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*valid_patterns(int n)
{
	char	*block_pattern[20];

	block_pattern[0] = "##..#...#";
	block_pattern[1] = "..##...#...#";
	block_pattern[2] = "#...#...##";
	block_pattern[3] = "...#...#..##";
	block_pattern[4] = "###.#";
	block_pattern[5] = ".###...#";
	block_pattern[6] = "#...###";
	block_pattern[7] = "...#.###";
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

int	ft_strlen(char const *s)
{
	int	i = 0;
	while (s[++i])
		;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s1);
	if ((str = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	ncpy;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ncpy = n;
	if (ncpy > 9)
	{
		ft_putnbr(ncpy / 10);
		ft_putnbr(ncpy % 10);
	}
	else
	{
		ncpy += '0';
		ft_putchar(ncpy);
	}
}



void	ft_putstr(char const *str)
{
	int	i = 0;

	while (str[i]) {
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	nlen;
	size_t	i;
	size_t	j;

	nlen = ft_strlen(needle);
	i = 0;
	if (nlen == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (j == nlen - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
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

char	**ft_strsplit(const char *s, char c)
{
	int	i;
	int	nb_word;
	int	len_word;
	int	max_len_word;

	if (!s || !c)
		return (0);
	i = 0;
	nb_word = 0;
	max_len_word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			nb_word++;
			len_word = 0;
			while (s[i] != c && s[i++])
				len_word++;
			if (len_word > max_len_word)
				max_len_word = len_word;
		}
	}
	return (ft_get_word(s, c, nb_word, max_len_word));
}

//error functionm if error_value is one then stdout usage, if not than stdout error
int		error(int error_value)
{
	if (error_value)
		ft_putstr("usage: ./fillit source_file\n");
	else
		ft_putstr("error\n");
	return (0);
}

//checks to make sure the block is sixteen blocks and if there are four blocks to  make it a valid tetris piece
int		parse_pattern(char **tet)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (tet[i])
	{
		j = 0;
		count = 0;
		while ((tet[i][j] == '.' || tet[i][j] == '#') && tet[i][j++])
		{
			if (tet[i][j] == '#')
				count++;
		}
		if (!(count > 2 && count < 5) || j != 16)
			return (0);
		i++;
	}
	return (1);
}

//copies valid_pattern function into char **array
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

//checks if the tetris piece is a valid pattern with strstr
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
				if (tet[i+1] == '\0')
					return (1);
				i++;
				j = -1;
			}
			j++;
		}
		return (0);
	}
	return (0);
}

//checks if tetris piece is a valid four by four map and if its a valid piece
int		check(char **tet)
{
	char	**pattern;
	int		i;

	i = 0;
	pattern = tmp_pattern();
	if (validate(tet, pattern) && parse_pattern(tet))
		return (1);
	return (0);
}

//read and open file
char	*open_read(char *str)
{
	int		fd;
	int		i;
	char	buf[buf_size];
	char	*tetBlock;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		error(0);
		exit(1);
	}
	i = read(fd, buf, buf_size);
	if (i == 0)
		return (0);
	buf[i] = '\0';
	tetBlock = buf;
	close (fd);
	return (tetBlock);
}

//remove newline and replaces string completely
char *rm_newline(char *s)
{
	char	*str;
	int		i;

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

char	**trim_tet(char **tet)
{
	char	**pattern;
	int		i;
	int		j;

	pattern = tmp_pattern();
	i = 0;
	j = 0;
	while (tet[i])
	{
		while (pattern[j] && tet[i])
		{
			if (bool_strstr(tet[i], pattern[j]))
			{
				tet[i++] = ft_strdup(pattern[j]);
				j = -1;
			}
			j++;
		}
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
		i++;
	}
	tet = NULL;
	return (tet);
}

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
	{
		i++;
	}
	return (i);
}

/*char	*make_map(int n)
{
	char	*map;
	int		len;

	len = n * n + n;
	if (!(map = (char *)malloc(len + 1)))
		return (0);
	map[len] = '\0';
	while (--len >= 0)
	{
		if (((len - n) % (n + 1)) == 0)
			map[len] = '\n';
		else
			map[len] = '.';
	}
	return (map);
}*/

char	*make_map(int n)
{
	int		len;
	char	*map;
	int		i;
//	int		count;

	len = n * n + n;
	if (!(map = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i <= len)
	{
			map[i] = '.';
			i++;
	}
	return (0);
}


int		main(int argc, char **argv)
{
	char	**tet;
	char	*map;
	int		map_size;

	if (argc == 1)
		return (error(1));
	if (!open_read(argv[1]))
		return (error(0));
	if (!(tet = ft_strsplit(rm_newline(open_read(argv[1])), '\n')) || !check(tet))
		return (error(0));
	map_size = cal_map_size(4 * count(tet));
	map = make_map(map_size);
	printf("%s", map);
	return (0);
}
