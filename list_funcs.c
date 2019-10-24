/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:09:26 by aolen             #+#    #+#             */
/*   Updated: 2019/09/18 19:09:28 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_tetriminos    *listnew(char **tab)
{
    int i;
    int j;

    i = -1;
    t_tetriminos    *new_el;
    if (!(new_el = malloc(sizeof(*new_el))))
        return (NULL);
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            
        }
    }
}