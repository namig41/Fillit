/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:15:51 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/07 15:12:53 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int				init_map(char ***map)
{
	int			i;
	int			j;

	i = -1;
	if (!(*map = (char **)malloc(sizeof(char *) * g_max_size)))
		delete_tetro_list(TETRO_SIZE);
	while (++i < g_max_size)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (g_max_size + 1))))
		{
			delete_2d(map, i);
			delete_tetro_list(TETRO_SIZE);
		}
		j = -1;
		while (++j < g_max_size)
			(*map)[i][j] = '.';
		(*map)[i][j] = '\0';
	}
	return (1);
}

int				draw_shape(char **map, t_tetriminos *obj, int off_i, int off_j)
{
	int			i;
	int			j;

	i = -1;
	if ((map[off_i][off_j] == '.' ||
		(map[off_i][off_j] != '.' && obj->shape[0][0] == '.')))
		while (++i < obj->height)
		{
			j = -1;
			while (++j < obj->width)
			{
				if (obj->shape[i][j] != '.' && map[off_i + i][off_j + j] == '.')
					map[i + off_i][j + off_j] = obj->letter;
				else if (obj->shape[i][j] != '.' &&
					map[off_i + i][off_j + j] != '.')
				{
					delete_shape(map, obj, off_i, off_j);
					return (0);
				}
			}
		}
	else
		return (0);
	return (1);
}

void			delete_shape(char **map, t_tetriminos *obj,
								int off_i, int off_j)
{
	int			i;
	int			j;

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

int				search(char **map, int count_figure, int index)
{
	int			i;
	int			j;

	i = -1;
	if (index == count_figure)
	{
		while (++i < g_max_size)
			ft_putendl(map[i]);
		return (1);
	}
	while (++i < g_max_size)
	{
		j = -1;
		while (++j < g_max_size)
			if (i <= g_max_size - g_tetro_list[index].height &&
			j <= g_max_size - g_tetro_list[index].width &&
			draw_shape(map, &g_tetro_list[index], i, j))
			{
				if (search(map, count_figure, index + 1))
					return (1);
				else
					delete_shape(map, &g_tetro_list[index], i, j);
			}
	}
	return (0);
}

void			search_solve(int count_figure)
{
	char		**map;

	g_max_size = ft_sqrt(g_max_size * 4);
	while (1)
	{
		if (!init_map(&map))
			return ;
		if (search(map, count_figure, 0))
		{
			delete_2d(&map, g_max_size);
			while (--count_figure >= 0)
				delete_2d(&g_tetro_list[count_figure].shape,
						g_tetro_list[count_figure].height);
			return ;
		}
		delete_2d(&map, g_max_size);
		g_max_size++;
	}
}
