/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:35:28 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/07 15:12:51 by lcarmelo         ###   ########.fr       */
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

static int	cheack_tetro(char **t)
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

static void	сreate_tetro(int fd, int *row, int *col)
{
	int		j;

	j = -1;
	if (!(g_tetro_list[g_max_size].shape =
			(char **)malloc(sizeof(char *) * TETRO_SIZE)))
		delete_tetro_list(g_max_size);
	while (++j < TETRO_SIZE)
	{
		if (get_next_line(fd, &g_tetro_list[g_max_size].shape[j]) <= 0)
			delete_tetro_list(j - 1);
		if (ft_strlen(g_tetro_list[g_max_size].shape[j]) != TETRO_SIZE)
			delete_tetro_list(j - 1);
		if (*row < 0 &&
		(*row = fl_strchr(g_tetro_list[g_max_size].shape[j], '#')) >= 0)
			*col = j;
	}
}

void		parse_file(int fd)
{
	int		row;
	int		col;
	char	*line;

	g_max_size = 0;
	while (1)
	{
		row = -1;
		сreate_tetro(fd, &row, &col);
		if (!cheack_tetro(g_tetro_list[g_max_size].shape))
			delete_tetro_list(TETRO_SIZE);
		if (row == -1 ||
		walk(g_tetro_list[g_max_size].shape, col, row) != TETRO_SIZE)
			delete_tetro_list(TETRO_SIZE);
		go_through_lines(&g_tetro_list[g_max_size]);
		g_tetro_list[g_max_size].letter = 'A' + g_max_size;
		if ((row = get_next_line(fd, &line)) >= 0 && !row && ++g_max_size)
			return ;
		else if (line && *line)
		{
			ft_memdel((void **)&line);
			delete_tetro_list(TETRO_SIZE - 3);
		}
		g_max_size++;
	}
}
