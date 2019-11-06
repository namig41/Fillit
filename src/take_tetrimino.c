/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:35:28 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/05 17:39:21 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "take_tetrimino.h"
#include <stdio.h>

void		delete_tetro_list(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_max_size)
	{
		j = -1;
		while (++j < TETRO_SIZE)
			ft_memdel((void **)&g_tetro_list[i].shape[j]);
		ft_memdel((void **)&g_tetro_list[i].shape);
	}
	ft_putendl("error");
	exit(0);
}



void		delete_2d(char ***arr)
{
	int i;

	i = -1;
	if (arr)
	{
		while (++i < g_max_size)
			ft_memdel((void **)&(*arr)[i]);
		ft_memdel((void **)&(*arr));
	}
}

int 		walk(char **t, int i, int j)
{
	int count;

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
#include <string.h>
void		parse_file(int fd)
{
	int		j;
	int		row;
	int		col;
	int		ch;
	char	*line;

	g_max_size = 0;
	while (1)
	{
		row = -1;
		j = -1;
		if (!(g_tetro_list[g_max_size].shape = (char **)malloc(sizeof(char *) * TETRO_SIZE)))
			delete_tetro_list();
		while (++j < TETRO_SIZE)
		{
			if (get_next_line(fd, &g_tetro_list[g_max_size].shape[j]) <= 0)
				delete_tetro_list();
			if (strlen(g_tetro_list[g_max_size].shape[j]) != TETRO_SIZE)
				delete_tetro_list();
			if (row < 0 && (row = fl_strchr(g_tetro_list[g_max_size].shape[j], '#')) >= 0)
				col = j;
		}
		if (walk(g_tetro_list[g_max_size].shape, col, row) != TETRO_SIZE)
			delete_tetro_list();
		go_through_lines(&g_tetro_list[g_max_size]);
		g_tetro_list[g_max_size].letter = 'A' + g_max_size;
		if ((ch = get_next_line(fd, &line)) >= 0 && !ch && ++g_max_size)
			return ;
		else if (line && *line)
		{
			//ft_memdel((void **)&line);
			delete_tetro_list();
		}
		g_max_size++;
	}
}
