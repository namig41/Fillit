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

int		permutation(char **map, t_tetriminos *objects, int count_f, int index, int map_size);
int		accommodation(char **map, t_tetriminos *objects, int count_f, int map_size);
int		check_object(char **map, t_tetriminos obj, int *off_x, int *off_y, int map_size);
void	search_solve(t_tetriminos *objects, int count_f, int map_size);
int		walk(char **map, t_tetriminos obj, int off_x, int off_y, int map_size);
void	init_map(char ***map, int map_size);
void	reset_map(char **map, int map_size);
void	destroy_map(char ***map, int map_size);
void	draw_map(char **map, int map_size);

#endif
