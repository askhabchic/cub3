/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:11 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/19 20:53:38 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	find_dir_2(t_all *all)
{
	if (all->plr.dir == 'E')
	{
		all->mlx.dirx = 1;
		all->mlx.diry = 0;
		all->mlx.planeX = 0;
		all->mlx.planeY = 0.66;
	}
	else if (all->plr.dir == 'N')
	{
		all->mlx.dirx = 0;
		all->mlx.diry = -1;
		all->mlx.planeX = 0.66;
		all->mlx.planeY = 0;
	}
}

void	find_dir(t_all *all)
{
	if (all->plr.dir == 'S')
	{
		all->mlx.dirx = 0;
		all->mlx.diry = 1;
		all->mlx.planeX = -0.66;
		all->mlx.planeY = 0;
	}
	else if (all->plr.dir == 'W')
	{
		all->mlx.dirx = -1;
		all->mlx.diry = 0;
		all->mlx.planeX = 0;
		all->mlx.planeY = -0.66;
	}
	else if (all->plr.dir == 'E' || all->plr.dir == 'N')
		find_dir_2(all);
}

void	find_spr(t_all *all)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	all->spr.arr = malloc(sizeof(t_sp) * all->spr.sp_num);
	if (all->spr.arr == NULL)
		error("Error of memory");
	y = 0;
	while (all->flags.map[y])
	{
		x = 0;
		while (all->flags.map[y][x])
		{
			if (ft_strchr("2", all->flags.map[y][x]))
			{
				all->spr.arr[i].x = x + 0.5;
				all->spr.arr[i].y = y + 0.5;
				all->spr.arr[i].order = i;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	plr_search(t_all *all)
{
	int		y;
	int		x;

	y = 0;
	all->spr.sp_num = 0;
	while (all->flags.map[y])
	{
		x = 0;
		while (all->flags.map[y][x])
		{
			if (ft_strchr("SWEN", all->flags.map[y][x]))
			{
				all->plr.x = x + 0.5;
				all->plr.y = y + 0.5;
				all->plr.dir = all->flags.map[y][x];
			}
			if (ft_strchr("2", all->flags.map[y][x]))
				all->spr.sp_num++;
			x++;
		}
		y++;
	}
	find_spr(all);
	find_dir(all);
}
