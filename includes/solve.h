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
# include "take_tetrimino.h"

void	search_solve();
int		init_map(char ***map, int size);
int		draw_shape(char **map, t_tetriminos *obj, int off_i, int off_j);
void	delete_shape(char **map, t_tetriminos *obj, int off_i, int off_j);
int		search(char **map, int size, int index);

#endif
