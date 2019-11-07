/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:03:14 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/07 20:03:17 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE	5
# if BUFF_SIZE < 0
#  error "BUFF_SIZE has wrong size"
# endif
# define SEPARATOR '\n'
# define MAX_FILES	100000
# define MEM_ERR -1

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

int			get_next_line(const int fd, char **line);

#endif
