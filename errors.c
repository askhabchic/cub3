/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:44:03 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/21 20:38:55 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	error_gnl(t_all *all, char **line)
{
	int		i;

	i = get_next_line(all->flags.map_fd, line);
	if (i == -1)
	{
		free (line);
		error("Error: read error");
	}
	else
		return (i);
	return (0);
}

void	error(char *str)
{
	printf("%s\n", str);
	exit (1);
}

int	quit(int key)
{
	if (key == 17)
		exit (1);
	return (0);
}
