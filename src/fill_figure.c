/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:24 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/05 17:35:29 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "take_tetrimino.h"

void		fill_tetrimino(char **x, t_tetriminos *temp)
{
	int		i;
	int		j;
	int		m;
	int		n;

	i = -1;
	m = 0;
	while (++i < TETRO_SIZE)
	{
		if ((i != 0) && ((n + 1) == temp->width) && ((m + 1) < temp->height))
			m++;
		n = -1;
		j = -1;
		while (++j < TETRO_SIZE)
			if (temp->shape[i][j] != '0')
				x[m][++n] = temp->shape[i][j];
	}
	delete_2d(&temp->shape, TETRO_SIZE);
	temp->shape = x;
}

char		**create_array(int wid, int high)
{
	int		i;
	char	**x;

	i = -1;
	if (!(x = (char **)malloc(sizeof(char *) * (high + 1))))
		delete_tetro_list();
	while (++i < high)
		if (!(x[i] = (char *)malloc(sizeof(char *) * wid)))
			delete_tetro_list();
	x[high] = NULL;
	return (x);
}

void		go_through_columns(char **x, t_tetriminos *temp)
{
	int		kol;
	int		i;
	int		j;

	j = -1;
	while (++j < TETRO_SIZE)
	{
		i = -1;
		kol = 0;
		while (++i < TETRO_SIZE)
		{
			if (temp->shape[i][j] == '.' || temp->shape[i][j] == '0')
				kol++;
		}
		if (kol == TETRO_SIZE)
		{
			temp->width -= 1;
			i = -1;
			while (++i < TETRO_SIZE)
				temp->shape[i][j] = '0';
		}
	}
	x = create_array(temp->width, temp->height);
	fill_tetrimino(x, temp);
}

void		go_through_lines(t_tetriminos *temp)
{
	int		kol;
	int		i;
	int		j;
	char	**x;

	i = -1;
	temp->height = TETRO_SIZE;
	temp->width = TETRO_SIZE;
	while (++i < TETRO_SIZE)
	{
		j = -1;
		kol = 0;
		while (++j < TETRO_SIZE && temp->shape[i][j] == '.')
			kol++;
		if (kol == TETRO_SIZE)
		{
			temp->height -= 1;
			j = -1;
			while (++j < TETRO_SIZE)
				temp->shape[i][j] = '0';
		}
	}
	go_through_columns(x, temp);
}
