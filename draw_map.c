/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:10:45 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/20 19:54:33 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	calc_perpdist(t_all *all, t_win *mlx)
{
	if (mlx->side == 0)
		mlx->perpdist = ((double)mlx->mapx - mlx->posx
				+ (double)((1 - mlx->stepx) / 2)) / mlx->raydirx;
	else
		mlx->perpdist = ((double)mlx->mapy - mlx->posy
				+ (double)((1 - mlx->stepy) / 2)) / mlx->raydiry;
	mlx->lineheight = (int)(all->flags.ry / mlx->perpdist);
	mlx->start = -mlx->lineheight / 2 + all->flags.ry / 2;
	if (mlx->start < 0)
		mlx->start = 0;
	mlx->end = mlx->lineheight / 2 + all->flags.ry / 2;
	if (mlx->end >= all->flags.ry)
		mlx->end = all->flags.ry - 1;
	check_side(all);
	mlx->zBuffer[mlx->x] = mlx->perpdist;
	mlx->x++;
}

void	check_hit(t_all *all)
{
	if (all->mlx.sidex < all->mlx.sidey)
	{
		all->mlx.sidex += all->mlx.deltax;
		all->mlx.mapx += all->mlx.stepx;
		all->mlx.side = 0;
	}
	else
	{
		all->mlx.sidey += all->mlx.deltay;
		all->mlx.mapy += all->mlx.stepy;
		all->mlx.side = 1;
	}
}

void	check_raydir(t_win *mlx)
{
	if (mlx->raydirx < 0)
	{
		mlx->stepx = -1;
		mlx->sidex = (mlx->posx - mlx->mapx) * mlx->deltax;
	}
	else
	{
		mlx->stepx = 1;
		mlx->sidex = (mlx->mapx + 1.0 - mlx->posx) * mlx->deltax;
	}
	if (mlx->raydiry < 0)
	{
		mlx->stepy = -1;
		mlx->sidey = (mlx->posy - mlx->mapy) * mlx->deltay;
	}
	else
	{
		mlx->stepy = 1;
		mlx->sidey = (mlx->mapy + 1.0 - mlx->posy) * mlx->deltay;
	}
}

void	calc_delta(t_all *all)
{
	all->mlx.mapx = (int)all->mlx.posx;
	all->mlx.mapy = (int)all->mlx.posy;
	all->mlx.deltax = fabs(1 / all->mlx.raydirx);
	all->mlx.deltay = fabs(1 / all->mlx.raydiry);
}

void	draw_map(t_all *all)
{
	int		y;
	int		hit;
	double	camerax;

	y = 0;
	all->mlx.x = 0;
	all->mlx.zBuffer = malloc(sizeof(double) * all->flags.rx);
	while (all->mlx.x < all->flags.rx)
	{
		camerax = 2 * all->mlx.x / (double)all->flags.rx - 1;
		all->mlx.raydirx = all->mlx.dirx + all->mlx.planeX * camerax;
		all->mlx.raydiry = all->mlx.diry + all->mlx.planeY * camerax;
		calc_delta(all);
		hit = 0;
		check_raydir(&all->mlx);
		while (hit == 0)
		{
			check_hit(all);
			if (all->flags.map[all->mlx.mapy][all->mlx.mapx] == '1')
				hit = 1;
		}
		calc_perpdist(all, &all->mlx);
	}
	draw_sprite(all);
	free(all->mlx.zBuffer);
}
