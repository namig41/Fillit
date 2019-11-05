/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:15:51 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/05 15:15:14 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int		init_map(char ***map)
{
	int i;
	int j;

	i = -1;
	if (!(*map = (char **)malloc(sizeof(char *) * g_max_size)))
		return (0);
	while (++i < g_max_size)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (g_max_size + 1))))
		{
			delete_2d(map);
			return (0);
		}
		j = -1;
		while (++j < g_max_size)
			(*map)[i][j] = '.';
		(*map)[i][j] = '\0';
	}
	return (1);
}

int		draw_shape(char **map, t_tetriminos *obj, int off_i, int off_j)
{
	int i;
	int j;

	i = -1;
	while (++i < obj->height)
	{
		j = -1;
		while (++j < obj->width)
		{
			if (obj->shape[i][j] != '.' &&
				map[off_i + i][off_j + j] == '.')
				map[i + off_i][j + off_j] = obj->letter;
			else if (obj->shape[i][j] != '.' &&
				map[off_i + i][off_j + j] != '.')
			{
				delete_shape(map, obj, off_i, off_j);
				return (0);
			}
		}
	}
	return (1);
}

int		walk(char **map, t_tetriminos *obj, int i, int j)
{
	int off_i;
	int off_j;

	off_i = i;
	while (++off_i <= g_max_size - obj->height)
	{
		off_j = j;
		while (++off_j <= g_max_size - obj->width)
			if ((map[off_i][off_j] == '.' ||
				(map[off_i][off_j] != '.' && obj->shape[0][0] == '.')) &&
				draw_shape(map, obj, off_i, off_j))
				return (1);
	}
	return (0);
}

int		search(char **map, t_tetriminos *shapes, int count_figure, int index)
{
	int i;
	int j;

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
		{
			if (!walk(map, &shapes[index], i - 1, j - 1))
				return (0);
			if (search(map, shapes, count_figure, index + 1))
				return (1);
			else
				delete_shape(map, &shapes[index], i, j);
		}
	}
	return (0);
}

void	search_solve(t_tetriminos *shapes, int count_figure)
{
	char **map;

	while (1)
	{
		if (!init_map(&map))
			return ;
		if (search(map, shapes, count_figure, 0))
		{
			delete_2d(&map);
			return ;
		}
		delete_2d(&map);
		g_max_size++;
	}
}
