/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:19:41 by sstench           #+#    #+#             */
/*   Updated: 2019/11/03 19:26:02 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_alone(char **shape_arr, int x, int y)
{
	if (y < 3 && shape_arr[x][y + 1] == 'P')
		return (1);
	else if (y > 0 && shape_arr[x][y - 1] == 'P')
		return (1);
	else if (x < 3 && shape_arr[x + 1][y] == 'P')
		return (1);
	else if (x > 0 && shape_arr[x - 1][y] == 'P')
		return (1);
	else
		return (0);
}

int	check_right(char **shape_arr, int x, int y, int blocks)
{
	if (blocks != 0)
	{
		if (check_alone(shape_arr, x, y + 1) == 1)
		{
			shape_arr[x][y + 1] = 'P';
			return (1);
		}
	}
	else
	{
		shape_arr[x][y + 1] = 'P';
		return (1);
	}
	return (0);
}

int	check_left(char **shape_arr, int x, int y, int blocks)
{
	if (blocks != 0)
	{
		if (check_alone(shape_arr, x, y - 1) == 1)
		{
			shape_arr[x][y - 1] = 'P';
			return (1);
		}
	}
	else
	{
		shape_arr[x][y - 1] = 'P';
		return (1);
	}
	return (0);
}

int	check_up(char **shape_arr, int x, int y, int blocks)
{
	if (blocks != 0)
	{
		if (check_alone(shape_arr, x + 1, y) == 1)
		{
			shape_arr[x + 1][y] = 'P';
			return (1);
		}
		return (0);
	}
	else
	{
		shape_arr[x + 1][y] = 'P';
		return (1);
	}
}

int	check_down(char **shape_arr, int x, int y, int blocks)
{
	if (blocks != 0)
	{
		if (check_alone(shape_arr, x - 1, y) == 1)
		{
			shape_arr[x - 1][y] = 'P';
			return (1);
		}
		return (0);
	}
	else
	{
		shape_arr[x - 1][y] = 'P';
		return (1);
	}
}
