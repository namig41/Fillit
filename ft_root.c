/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:35 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/13 12:35:37 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long			ft_root(unsigned long long num)
{
	unsigned long long root;
	unsigned long long i;

	root = num;
	if (root + 1 < root)
		return (0);
	if (root == 1)
		return (root);
	i = 1;
	while (i <= root)
	{
		if (i * i >= root * 4)
			return (i);
		i++;
	}
	return (0);
}
