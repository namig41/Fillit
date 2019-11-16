/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:04:30 by aolen             #+#    #+#             */
/*   Updated: 2019/11/16 16:22:51 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define TETRO_SIZE 4

typedef struct	s_tetriminos
{
	char		**shape;
	char		letter;
	int			width;
	int			height;
}				t_tetriminos;

t_tetriminos g_tl[26];
int				g_ms;

#endif
