/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:15:51 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/16 18:02:15 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int				init_map(char ***map, int size)
{
	int			i;
	int			j;

	i = -1;
	if (!(*map = (char **)malloc(sizeof(char *) * size)))
		delete_tetro_list();
	while (++i < size)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			delete_2d(map, i);
			delete_tetro_list();
		}
		j = -1;
		while (++j < size)
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

int				search(char **map, int size, int index)
{
	int			i;
	int			j;

	i = -1;
	if (index == g_ms)
	{
		while (++i < size)
			ft_putendl(map[i]);
		return (1);
	}
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (i <= size - g_tl[index].height &&
					j <= size - g_tl[index].width &&
					draw_shape(map, &g_tl[index], i, j))
			{
				if (search(map, size, index + 1))
					return (1);
				else
					delete_shape(map, &g_tl[index], i, j);
			}
	}
	return (0);
}

void			search_solve(void)
{
	char		**map;
	int			size;

	size = ft_sqrt(g_ms * 4);
	while (1)
	{
		if (!init_map(&map, size))
			return ;
		if (search(map, size, 0))
		{
			delete_2d(&map, size);
			while (--g_ms >= 0)
				delete_2d(&g_tl[g_ms].shape, g_tl[g_ms].height);
			return ;
		}
		delete_2d(&map, size);
		size++;
	}
}
