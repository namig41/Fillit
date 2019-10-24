/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:37:39 by aolen             #+#    #+#             */
/*   Updated: 2019/09/19 20:30:41 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

#include <stdio.h>

struct s_figure
{
    int x;
    int y;
} g_figure;

//static void print_tetr(char **tetr)
//{
//    int i;
//
//    i = -1;
//    while (++i < 4)
//        printf("%d: %s\n", i, tetr[i]);
//}

static int check_fig(char **tab, int i, int j)
{
    int size = 0;
	
    size++;
    tab[i][j] = REPLACE_SYM;
    if (j > 0 && tab[i][j - 1] == '#')
	{
    	size += check_fig(tab, i, j - 1);
	}
    if (j < 3 && tab[i][j + 1] == '#')
    {
    	size += check_fig(tab, i, j + 1);
    }
    if (i > 0 && tab[i - 1][j] == '#')
    {
    	size += check_fig(tab, i - 1, j);
    }
    if (i < 3 && tab[i + 1][j] == '#')
    {
    	size += check_fig(tab, i + 1, j);
    }
    return (size);
}

int check_tetr(char **tab)
{
	int i;
    int j;
    unsigned int len;
    int size;

    i = -1;
    size = 0;
    while (++i < 4)
    {
        if ((len = ft_strlen(tab[i])) < 4)
            return (LEN_ERR);
        j = -1;
        while (++j < 4)
        {
        	if (tab[i][j] != '.' && tab[i][j] != '#')
        		return (SYM_ERR);
        	if (tab[i][j] == '#')
        	{
        		size++;
        		if (size > 4)
        			return (FIG_ERR);
        		if (size == 1)
		   		{
	   				g_figure.x = i;
	   				g_figure.y = j;
        		}
        	}
        }
    }
    if (size < 4 || (size = check_fig(tab, g_figure.x, g_figure.y)) < 4)
    	return (FIG_ERR);
    //print_tetr(tab);
    return (1);
}
