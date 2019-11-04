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

int g_max_size = 0;

void            delete_tetro_list()
{
    int i;
    int j;

    i = -1;
    while (++i < g_max_size)
    {
        j = -1;
        while (++j < N)
            free(g_tetro_list[i].shape[j]);
        free(g_tetro_list[i].shape);
    }
    exit(0);
}

void            parse_file(int fd)
{
    int         i;
    int         ch;
    char        *line;

    while (1)
    {
        i = 0;
        if (!(g_tetro_list[g_max_size].shape = (char **)malloc(sizeof(char *) * N)))
            delete_tetro_list();
        while (i < N)
        {
            if (get_next_line(fd, &g_tetro_list[g_max_size].shape[i]) < 0)
                delete_tetro_list();
            i++;
        }
        go_through_lines(&g_tetro_list[g_max_size]);
        g_tetro_list[g_max_size].letter = 'A' + g_max_size;
        if ((ch = get_next_line(fd, &line)) >= 0 && !*line)
        {
            if (!ch)
            {
                g_max_size++;
                return ;
            }
        }
        else
        {
            free(line);
            delete_tetro_list();
        }
        g_max_size++;
    }
}