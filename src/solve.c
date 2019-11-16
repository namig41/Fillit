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
	if (!(*map = (char **)malloc(sizeof(char *) * g_ms)))
		delete_tetro_list();
	while (++i < g_ms)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (g_ms + 1))))
		{
			delete_2d(map, i);
			delete_tetro_list();
		}
		j = -1;
		while (++j < g_ms)
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
		while (++i < g_ms)
			ft_putendl(map[i]);
		return (1);
	}
	while (++i < g_ms)
	{
		j = -1;
		while (++j < g_ms)
			if (i <= g_ms - g_tl[index].height &&
			j <= g_ms - g_tl[index].width &&
			draw_shape(map, &g_tl[index], i, j))
			{
				if (search(map, count_figure, index + 1))
					return (1);
				else
					delete_shape(map, &g_tl[index], i, j);
			}
	}
	return (0);
}

void			search_solve(int count_figure)
{
	char		**map;

        g_ms = ft_sqrt(g_ms * 4);
	while (1)
	{
		if (!init_map(&map))
			return ;
		if (search(map, count_figure, 0))
		{
			delete_2d(&map, g_ms);
			while (--count_figure >= 0)
				delete_2d(&g_tl[count_figure].shape,
                                    g_tl[count_figure].height);
			return ;
		}
		delete_2d(&map, g_ms);
                g_ms++;
	}
}
