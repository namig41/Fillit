/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:03:29 by sstench           #+#    #+#             */
/*   Updated: 2019/11/03 19:36:46 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_near(char **shape_arr, int x, int y, int blocks)
{
	if (y < 3 && shape_arr[x][y + 1] == '#')
		return (check_right(shape_arr, x, y, blocks));
	else if (y > 0 && shape_arr[x][y - 1] == '#')
		return (check_left(shape_arr, x, y, blocks));
	else if (x < 3 && shape_arr[x + 1][y] == '#')
		return (check_up(shape_arr, x, y, blocks));
	else if (x > 0 && shape_arr[x - 1][y] == '#')
		return (check_down(shape_arr, x, y, blocks));
	else
		return (0);
}

int		checker(char **shape_arr)
{
	int len;
	int valid;
	int blocks;
	int index;

	index = -1;
	valid = 1;
	blocks = 0;
	while (++index < 4)
	{
		len = -1;
		while (++len < 4)
			blocks += check_near(shape_arr, index, len, blocks);
	}
	if (blocks > 4 || blocks < 4)
		return (valid - 1);
	return (valid);
}

int		skip_checker(char **shape_arr)
{
	int index;
	int x;
	int blocks;

	index = -1;
	blocks = 0;
	while (++index < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (shape_arr[index][x] == '#')
				blocks++;
			else if (shape_arr[index][x] != '.')
				return (0);
		}
	}
	if (blocks == 4)
		return (1);
	return (0);
}

char	**filler(char **shape_arr, int x, int y)
{
	int width;
	int	height;

	width = 0;
	height = 0;
	while (width < 4)
	{
		while (height <= 4)
		{
			if (height == 4)
				shape_arr[width][height] = '\0';
			if (shape_arr[width][height] == 'P')
				shape_arr[width][height] = '#';
			height++;
		}
		height = 0;
		width++;
	}
	return (shape_arr);
}

int	start_check(char **shape_arr)
{
	int		x;
	int		y;
	int		valid;

	x = 4;
	y = 5;
	valid = skip_checker(shape_arr);
	if (valid == 1)
		valid = checker(shape_arr);
	filler(shape_arr, x, y);
	return (valid);
}
