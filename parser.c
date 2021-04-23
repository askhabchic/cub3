/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:29:27 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/20 20:27:46 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	plr_init(t_all *all)
{
	all->plr.a = 0;
	all->plr.s = 0;
	all->plr.d = 0;
	all->plr.w = 0;
	all->plr.left = 0;
	all->plr.right = 0;
	all->plr.x = -1;
	all->plr.y = -1;
}

void	map_init(t_all *all)
{
	all->flags.map_name = NULL;
	all->flags.no = NULL;
	all->flags.so = NULL;
	all->flags.we = NULL;
	all->flags.ea = NULL;
	all->flags.sp = NULL;
	all->flags.flag_dir = NULL;
	all->flags.rx = -1;
	all->flags.ry = -1;
	all->flags.ceil = -1;
	all->flags.flo = -1;
	all->flags.map_fd = 0;
	all->flags.map = NULL;
	all->flags.nlines = 0;
	all->flags.maplines = 0;
	all->flags.save = 0;
	all->flags.maphere = 0;
	all->flags.maxlen = 0;
	all->flags.player = NULL;
	all->flags.overx = 0;
	all->flags.overy = 0;
}

int	parser(char *line, t_all *all)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
	}
	if (line[i] == 'R')
	{
		check_resol(line, all);
		if (all->flags.rx <= 0 || all->flags.ry <= 0)
			exit (1);
	}
	else if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'S')
		check_texture(line, all);
	else if (line[i] == 'F' || line[i] == 'C' )
		check_c(line, all);
	else if (line[0] == '\0' && all->flags.maphere == 0)
		return (0);
	else
		check_map(line, all);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
