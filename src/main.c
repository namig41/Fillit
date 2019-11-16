/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:42:01 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/16 16:33:50 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "take_tetrimino.h"

int		main(int argc, char *argv[])
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	parse_file(fd);
	search_solve(g_ms);
	close(fd);
	return (0);
}
