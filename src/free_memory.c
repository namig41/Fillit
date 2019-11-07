/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:44:28 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/07 19:44:53 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "take_tetrimino.h"

void		delete_tetro_list(int h)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_max_size)
	{
		j = -1;
		while (++j < h)
			ft_memdel((void **)&g_tetro_list[i].shape[j]);
		ft_memdel((void **)&g_tetro_list[i].shape);
	}
	ft_putendl("error");
	exit(0);
}

void		delete_2d(char ***arr, int h)
{
	int i;

	i = -1;
	if (arr)
	{
		while (++i < h)
			ft_memdel((void **)&(*arr)[i]);
		ft_memdel((void **)&(*arr));
	}
}
