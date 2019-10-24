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

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void	draw_map(char **map, int map_size)
{
	int i;

	i = -1;
	while (++i < map_size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

void	reset_map(char **map, int map_size)
{
	int i;
	int j;

	i = -1;
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
}

void resize_map(char ***map, int map_size)
{
	int i;

	i = -1;
	while (++i < map_size)
		(*map)[i] = ft_realloc((*map)[i], map_size);
}

void	destroy_map(char ***map, int map_size)
{
	int i;

	i = -1;
	while (++i < map_size)
		free((*map)[i]);
	free(*map);
}

void	init_map(char ***map, int map_size)
{
	int i;

	i = -1;
	*map = (char **)malloc(sizeof(char *) * map_size);
	while (++i < map_size)
		(*map)[i] = (char *)malloc(sizeof(char) * (map_size + 1));
}


int 	walk(char **map, t_tetriminos obj, int off_x, int off_y, int map_size)
{
	int i;
	int j;

	i = off_y;
	while (i < obj.height + off_y && i < map_size)
	{
		j = off_x;
		while (j < obj.width + off_x && j < map_size)
		{
			if (map[i][j] != '.' && obj.shape[i - off_y][j - off_x] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_object(char **map, t_tetriminos obj, int *off_x, int *off_y, int map_size)
{
	int x;

	while (*off_y + obj.height - 1 < map_size)
	{
		x = *off_x;
		while (x + obj.width - 1 < map_size)
		{
			if (walk(map, obj, x, *off_y, map_size))
			{
				*off_x = x;
				return (1);
			}
			x++;
		}
		(*off_y)++;
	}
	return (0);
}

int		accommodation(char **map, t_tetriminos *objects, int count_figure, int map_size)
{
	int i;
	int j;
	int k;
	int offsetX;
	int offsetY;

	k = -1;
	reset_map(map, map_size);
	while (++k < count_figure)
	{
		i = -1;
		while (++i < objects[k].height)
		{
			j = -1;
			while (++j < objects[k].width)
			{
				if (k != 0 && i == 0 && j == 0)
				{
					offsetX = 0;
					offsetY = 0;
					if (!check_object(map, objects[k], &offsetX, &offsetY, map_size))
						return (0);
				}
				if (objects[k].shape[i][j] != '.')
					map[i + offsetY][j + offsetX] = objects[k].letter;
			}
		}
	}
	return (1);
}

int		permutation(char **map, t_tetriminos *objects, int count_figure, int index, int map_size)
{
	int i;

	i = index;
	if (index == count_figure)
	{
		if (accommodation(map, objects, count_figure, map_size))
		{
			draw_map(map, map_size);
			return (1);
		}
	}
	else
	{
		while (i < count_figure)
		{
			ft_swap(&objects[i], &objects[index], sizeof(t_tetriminos));
			if (permutation(map, objects, count_figure, index + 1, map_size))
				return (1);
			ft_swap(&objects[i], &objects[index], sizeof(t_tetriminos));
			i++;
		}
	}
	return (0);
}

void	search_solve(t_tetriminos *objects, int count_figure, int map_size)
{
	char **map;

	while (1)
	{
		init_map(&map, map_size);
		if (permutation(map, objects, count_figure, 0, map_size))
		{
			destroy_map(&map, map_size);
			return ;
		}
		destroy_map(&map, map_size);
		map_size++;
	}
}
