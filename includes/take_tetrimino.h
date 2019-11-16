/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_shapes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:22:00 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/10/29 17:22:03 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAKE_TETRIMINO_H
# define TAKE_TETRIMINO_H
# include "fillit.h"
# include "get_next_line.h"

void	delete_2d(char ***arr, int h);
void	delete_tetro_list();
void	parse_file(int fd);
int		walk(char **t, int i, int j);
void	fill_tetrimino(char **x, t_tetriminos *temp);
void	go_through_columns(char **x, t_tetriminos *temp);
void	go_through_lines(t_tetriminos *temp);
char	**create_array(int wid, int high);

#endif
