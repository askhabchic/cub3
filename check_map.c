/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:09:05 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/20 21:20:40 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_map_line(t_all *all, char *line)
{
	int		i;
	char	*c;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == '2'
				|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
				|| line[i] == 'N' || line[i] == ' '))
			error("Error: invalid values on the map");
		c = ft_strchr("SWEN", line[i]);
		if (c != NULL && all->flags.player == NULL)
			all->flags.player = c;
		else if (all->flags.player != NULL && c != NULL)
			error("Error: too muany players on the map");
		i++;
	}
	if (line[0] == '\0' && all->flags.maphere == 1)
		error("Error: invalid values on the map");
}

int	all_flags(t_all *all)
{
	if (all->flags.rx != -1 && all->flags.ry != -1 && all->flags.no != NULL
		&& all->flags.so != NULL && all->flags.we != NULL && all->flags.ea
		!= NULL && all->flags.sp != NULL && all->flags.ceil != -1
		&& all->flags.flo != -1)
		return (1);
	else
		return (0);
}

void	check_map(char *s, t_all *all)
{
	int		i;
	int		k;

	i = 0;
	k = all_flags(all);
	if (k == 1 && s[i] != '\0')
	{
		if (s[i] == '1' || s[i] == '0' || s[i] == ' ' || s[i] == '\0')
		{
			while (s[i] == ' ')
				i++;
			if ((s[i] == '1' || s[i] == '0') && all->flags.maphere == 0
				&& all_flags(all) == 1)
				all->flags.maphere = 1;
			else if (((s[i]) != '1' || s[i] != '0')
				&& all->flags.maphere == 0 && s[i] != '\0')
				error("Error: values entered incorrectly");
			check_map_line(all, s);
		}
	}
	else
		error("Error: incomplete map");
}
