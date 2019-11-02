/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:51:44 by ngale             #+#    #+#             */
/*   Updated: 2019/11/02 15:05:34 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		fill_tetrimino(char **x, t_tetriminos *temp)
{
	int		i;
	int		j;
	int		m;
	int		n;

	i = -1;
	m = 0;
	while (++i < 4)
	{
		if ((i != 0) && ((n + 1) == temp->width) && ((m + 1) < temp->height))
			m++;
		n = -1;
		j = -1;
		while (++j < 4)
			if (temp->shape[i][j] == '.' || temp->shape[i][j] == '#')
				x[m][++n] = temp->shape[i][j];
	}
	i = -1;
	while (++i < 4)
		free(temp->shape[i]);
	free(temp->shape);
	temp->shape = x;	
}

char 		**create_array(int wid, int high)
{
	int		i;
	char 	**x;

	i = -1;
	x = (char **)malloc(sizeof(char *) * high);
	while (++i < high)
	{
		x[i] = (char *)malloc(sizeof(char) * wid);
		x[i][wid - 1] = '\0';
	}
	x[i] = NULL;
	return (x);
}

void		go_through_columns(char **x, t_tetriminos *temp)
{
	int		kol;
	int		i;
	int		j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		kol = 0;
		while (++i < 4)
		{
			if (temp->shape[i][j] == '.' || temp->shape[i][j] == '0')
				kol++;
		}
		if (kol == 4)
		{
			temp->width -= 1;
			i = 0;
			while (i < 4)
				temp->shape[i++][j] = '0';
		}
	}
	x = create_array(temp->width + 1, temp->height + 1);
	fill_tetrimino(x, temp);
}

void 				go_through_lines(t_tetriminos *temp)
{
	int				kol;
	int				i;
	int				j;
	char 			**x;

	i = -1;
	temp->height = 4;
	temp->width = 4;
	while (++i < 4)
	{
		j = -1;
			kol = 0;
			while (++j < 4 && temp->shape[i][j] == '.')
			kol++;
		if (kol == 4)
		{
			temp->height -= 1;
			j = -1;
			while (++j < 4)
				temp->shape[i][j] = '0';
		}
	}
	go_through_columns(x, temp);
}