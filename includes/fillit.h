/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:04:30 by aolen             #+#    #+#             */
/*   Updated: 2019/09/18 15:06:58 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_tetriminos
{
	char		**shape;
	char		letter;
	int			width;
	int			height;
}				t_tetriminos;

t_tetriminos	g_tetro_list[26];

#endif
