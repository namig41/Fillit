/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:15:51 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/10/24 17:43:42 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include <stdio.h>

void	draw_map(char **map, int map_size)
{
	int i;

	i = -1;
	while (++i < map_size)
		ft_putendl(map[i]);
}

void	destroy_map(char ***map, int map_size)
{
	while (--map_size >= 0)
		free((*map)[map_size]);
	free(*map);
}

int		init_map(char ***map, int map_size)
{
	int i;
	int j;

	i = -1;
	if (!(*map = (char **)malloc(sizeof(char *) * map_size)))
		return (0);
	while (++i < map_size)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (map_size + 1))))
		{
			destroy_map(map, i);
			return (0);
		}
		j = -1;
		while (++j < map_size)
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
			if (obj->shape[i][j] != '.' && map[off_i + i][off_j + j] == '.')
				map[i + off_i][j + off_j] = obj->letter;
			else if (obj->shape[i][j] != '.' && map[off_i + i][off_j + j] != '.')
			{
				delete_shape(map, obj, off_i, off_j);
				return (0);
			}
		}
	}
	return (1);
}

void 	delete_shape(char **map, t_tetriminos *obj, int off_i, int off_j)
{
	int i;
	int j;

	i = -1;
	while (++i < obj->height) 
	{
		j = -1;
		while (++j < obj->width)
			if (obj->shape[i][j] != '.' && map[i + off_i][j + off_j] == obj->letter)
				map[i + off_i][j + off_j] = '.';
	}
}

int		walk(char **map, t_tetriminos *obj, int map_size, int i, int j)
{
	int off_i;
	int off_j;

	off_i = i;
	while (++off_i <= map_size - obj->height) 
	{
		off_j = j;
		while (++off_j <= map_size - obj->width)
			if ((map[off_i][off_j] == '.' || (map[off_i][off_j] != '.' && obj->shape[0][0] == '.')) && draw_shape(map, obj, off_i, off_j))
				return (1);
	}
	return (0);
}

int		search(char **map, t_tetriminos *shapes, int count_figure, int current_shape, int map_size)
{
    int i;
    int j;

    i = -1;
	if (map_size == 6){

	draw_map(map, map_size);
	ft_putchar('\n');
	}
	if (current_shape == count_figure)
	{
		draw_map(map, map_size);
		return (1);
	}
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
		{
			if (!walk(map, &shapes[current_shape], map_size, i - 1, j - 1))
				return (0);
			if (search(map, shapes, count_figure, current_shape + 1, map_size))
				return (1);
			else
				delete_shape(map, &shapes[current_shape], i, j);
		}
	}
	return (0);
}

void	search_solve(t_tetriminos *shapes, int count_figure, int map_size)
{
	char **map;

	while (1)
	{
		if (!init_map(&map, map_size))
			return ;
		if (search(map, shapes, count_figure, 0, map_size))
		{
			destroy_map(&map, map_size);
			return ;
		}
		destroy_map(&map, map_size);
		map_size++;
	}
}
