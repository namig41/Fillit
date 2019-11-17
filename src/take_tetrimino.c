/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:35:28 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/16 18:00:44 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "take_tetrimino.h"

int			walk(char **t, int i, int j)
{
	int		count;

	count = 0;
	t[i][j] = '*';
	if (j + 1 < TETRO_SIZE && t[i][j + 1] == '#')
		count += walk(t, i, j + 1);
	if (j - 1 > -1 && t[i][j - 1] == '#')
		count += walk(t, i, j - 1);
	if (i + 1 < TETRO_SIZE && t[i + 1][j] == '#')
		count += walk(t, i + 1, j);
	if (i - 1 > -1 && t[i - 1][j] == '#')
		count += walk(t, i - 1, j);
	return (count + 1);
}

static int	fl_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

static int	check_tetro(char **t)
{
	int		i;
	int		j;

	i = -1;
	while (++i < TETRO_SIZE)
	{
		j = -1;
		while (++j < TETRO_SIZE)
			if (t[i][j] != '.' && t[i][j] != '#')
				return (0);
	}
	return (1);
}

static void	create_tetro(int fd, int *row, int *col)
{
	int		j;

	j = -1;
	if (!(g_tl[g_ms].shape =
				(char **)malloc(sizeof(char *) * (TETRO_SIZE + 1))))
		delete_tetro_list();
	g_tl[g_ms].shape[TETRO_SIZE] = NULL;
	while (++j < TETRO_SIZE)
	{
		if (get_next_line(fd, &g_tl[g_ms].shape[j]) <= 0)
		{
			g_tl[g_ms].shape[j] = NULL;
			delete_tetro_list();
		}
		if (ft_strlen(g_tl[g_ms].shape[j]) != TETRO_SIZE)
		{
			g_tl[g_ms].shape[j + 1] = NULL;
			delete_tetro_list();
		}
		if (*row < 0 && (*row = fl_strchr(g_tl[g_ms].shape[j], '#')) >= 0)
			*col = j;
	}
	if (!check_tetro(g_tl[g_ms].shape))
		delete_tetro_list();
}

void		parse_file(int fd)
{
	int		row;
	int		col;
	char	*line;

	g_ms = -1;
	while (++g_ms < 26)
	{
		row = -1;
		create_tetro(fd, &row, &col);
		if (row == -1 || walk(g_tl[g_ms].shape, col, row) != TETRO_SIZE)
			delete_tetro_list();
		go_through_lines(&g_tl[g_ms]);
		g_tl[g_ms].letter = 'A' + g_ms;
		if ((row = get_next_line(fd, &line)) >= 0 && !row && ++g_ms)
			return ;
		else if (line && *line)
		{
			ft_memdel((void **)&line);
			delete_tetro_list();
		}
		ft_memdel((void **)&line);
	}
	if (get_next_line(fd, &line) >= 0)
		delete_tetro_list();
}
