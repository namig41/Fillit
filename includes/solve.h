/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:08:21 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/09/21 17:22:02 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

#include "../libft/libft.h"
#include "fillit.h"

void	search_solve(t_tetriminos *shapes, int count_figure, int min_map_size);
int     init_map(char ***map, int map_size);
void	destroy_map(char ***map, int map_size);
void	draw_map(char **map, int map_size);
int     draw_shape(char **map, t_tetriminos *obj, int off_i, int off_j);
void    delete_shape(char **map, t_tetriminos *obj, int off_i, int off_j);
int     walk(char **map, t_tetriminos *obj, int map_size);

#endif
