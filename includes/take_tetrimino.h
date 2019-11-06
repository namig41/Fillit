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

#ifndef TAKE_SHAPES_H
# define TAKE_SHAPES_H
# include "fillit.h"
# include "get_next_line.h"

void    delete_2d(char ***arr);
void    delete_tetro_list();
void    parse_file(int fd);
int		walk(char **t, int i, int j);

#endif
