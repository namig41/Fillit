/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:17:24 by aolen             #+#    #+#             */
/*   Updated: 2019/09/21 17:36:03 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "get_next_line.h"
#include "solve.h"

#include <stdio.h>
#include "ft_root.c"

void print_tetr(char **tetr)
{
	int i;

	i = -1;
	while (tetr[++i])
		printf("%d: %s\n", i, tetr[i]);
	printf("%s\n", tetr[i]);
}

static int	read_n_write(int fd, char **shape)
{
	int		i;
	char	*ptr;
	int err;

	i = 0;
	while (get_next_line(fd, &ptr) > 0)
	{
		if (i % 5 == 4 && i / 4 > 0)
		{
			i++;
			continue;
		}
		shape[i % 5] = ptr;
		if (i % 5 == 3)
		{
			if ((err = check_tetr(shape)) > 0)
				tetrimino_collection(shape, i / 5);
			else
				return (err);
		}
		i++;
	}
	return ((i + 1) / 5);
}

int				main(int ac, char **av)
{
	char		*shape[4];
	int			fd;
	int			count_figure;
	int			size;

	size = 3;
	count_figure = 0;
	if (ac != 2)
		print_usage();
	else
	{
		fd = open(av[1], O_RDONLY);
		if ((count_figure = read_n_write(fd, shape)) < 0)
		{
			ft_putstr("error\n");
			return (1);
		}
		else
		{
			if (count_figure > 4)
				size = ft_root(count_figure);
			search_solve(g_tetro_list, count_figure, size);
		}
		close(fd);
	}
	return (0);
}
