/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:29:20 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/10/26 17:49:30 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *c[MAX_FILES] = {NULL};
	char		buf[BUFF_SIZE + 1];
	int			shift;
	int			n;
	char		*s;

	if ((shift = (fd < 0 || !line || fd >= MAX_FILES)))
		return (-1);
	while (!(s = ft_strchr(c[fd] + (shift += !shift ? 0 : n), SEPARATOR)))
	{
		if ((n = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		buf[n] = '\0';
		if (!(c[fd] = ft_strsave(c[fd], buf)))
			return (-1);
	}
	if ((!c[fd] && !n) || n < 0 || !*c[fd])
		return (n < 0 ? -1 : 0);
	n = s ? (s - c[fd]) : ft_strlen(c[fd]);
	if (!(*line = ft_strnew(n)) & !ft_strncpy(*line, c[fd], n))
		return (-1);
	s = s ? ft_strdup(s + 1) : NULL;
	ft_memdel((void *)&c[fd]);
	return ((c[fd] = s) == s);
}
