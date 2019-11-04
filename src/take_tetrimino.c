/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:21:36 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/10/29 17:21:37 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "take_tetrimino.h"

void            delete_tetro_list(int g_max_size)
{
    int i;
    int j;

    i = -1;
    while (++i < g_max_size)
    {
        j = -1;
        while (++j < TETRO_SIZE)
            ft_memdel((void **)&g_tetro_list[i].shape[j]);
        ft_memdel((void **)&g_tetro_list[i].shape);
    }
    exit(0);
}

int             parse_file(int fd)
{
    int         i;
    int         g_max_size;
    int         ch;
    char        *line;

    line = NULL;
    g_max_size = 0;
    while (1)
    {
        i = 0;
        if (!(g_tetro_list[g_max_size].shape = (char **)malloc(sizeof(char *) * TETRO_SIZE)))
            delete_tetro_list(g_max_size);
        while (i < TETRO_SIZE)
        {
            if (get_next_line(fd, &g_tetro_list[g_max_size].shape[i]) <= 0)
                delete_tetro_list(g_max_size);
            i++;
        }
        go_through_lines(&g_tetro_list[g_max_size]);
        g_tetro_list[g_max_size].letter = 'A' + g_max_size;
        if ((ch = get_next_line(fd, &line)) >= 0 && !ch)
        {
            g_max_size++;
            return (g_max_size);
        }
        else if (line && *line)
        {
            ft_memdel((void **)&line);
            delete_tetro_list(g_max_size);
        }
        g_max_size++;
    }
    return (g_max_size);
}
