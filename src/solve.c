/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:15:51 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/06 17:16:41 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

unsigned int			ft_root(unsigned int figs_num)
{
	unsigned int root;
	unsigned int i;

	root = figs_num * 4;
	if (root + 1 < root)
		return (0);
	i = 2;
	while (i <= root)
	{
		if (i * i >= root)
			return (i);
		i++;
	}
	return (0);
}

int		init_map(char ***map)
{
	int i;
	int j;

	i = -1;
	if (!(*map = (char **)malloc(sizeof(char *) * g_max_size)))
		delete_tetro_list();
	while (++i < g_max_size)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (g_max_size + 1))))
		{
			delete_2d(map);
			delete_tetro_list();
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
	if ((map[off_i][off_j] == '.' || (map[off_i][off_j] != '.' && obj->shape[0][0] == '.')))
	{
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
	}
	else
		return (0);
	return (1);
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
			if (i <= g_max_size - shapes[index].height && j <= g_max_size - shapes[index].width && draw_shape(map, &shapes[index], i, j))
			{
				if (search(map, shapes, count_figure, index + 1))
					return (1);
				else
					delete_shape(map, &shapes[index], i, j);
			}
		}
	}
	return (0);
}

void	search_solve(t_tetriminos *shapes, int count_figure)
{
	char **map;
	g_max_size = ft_root(g_max_size);

	while (1)
	{
		if (!init_map(&map))
			return ;
		if (search(map, shapes, count_figure, 0))
		{
			//delete_2d(&map);
			//delete_tetro_list();
			return ;
		}
		delete_2d(&map);
		g_max_size++;
	}
}
