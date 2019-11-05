/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:21:03 by sstench           #+#    #+#             */
/*   Updated: 2019/11/03 19:35:06 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

int		check_alone(char **shape_arr, int x, int y);
int		check_right(char **shape_arr, int x, int y, int blocks);
int		check_left(char **shape_arr, int x, int y, int blocks);
int		check_up(char **shape_arr, int x, int y, int blocks);
int		check_down(char **shape_arr, int x, int y, int blocks);
int		check_near(char **shape_arr, int x, int y, int blocks);
int		checker(char **shape_arr);
int		skip_checker(char **shape_arr);
int     start_check(char **shape_arr);
#endif
