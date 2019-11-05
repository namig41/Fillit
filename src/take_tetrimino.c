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
	exit(0);
}

void	delete_shape(char **map, t_tetriminos *obj, int off_i, int off_j)
{
	int i;
	int j;

	i = -1;
	while (++i < obj->height)
	{
		j = -1;
		while (++j < obj->width)
			if (obj->shape[i][j] != '.' &&
				map[i + off_i][j + off_j] == obj->letter)
				map[i + off_i][j + off_j] = '.';
	}
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

void		parse_file(int fd)
{
	int		i;
	int		ch;
	char	*line;

	g_max_size = 0;
	while (1)
	{
		i = -1;
		if (!(g_tetro_list[g_max_size].shape = (char **)malloc(sizeof(char *) * TETRO_SIZE)))
			delete_tetro_list();
		while (++i < TETRO_SIZE)
			if (get_next_line(fd, &g_tetro_list[g_max_size].shape[i]) <= 0)
				delete_tetro_list();
		if (!start_check(g_tetro_list[g_max_size].shape))
			delete_tetro_list();
		go_through_lines(&g_tetro_list[g_max_size]);
		g_tetro_list[g_max_size].letter = 'A' + g_max_size;
		if ((ch = get_next_line(fd, &line)) >= 0 && !ch)
		{
			g_max_size++;
			return ;
		}
		else if (line && *line)
		{
			//ft_memdel((void **)&line);
			delete_tetro_list();
		}
		g_max_size++;
	}
}
