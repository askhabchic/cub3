/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:31:27 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/19 20:31:33 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	key_press(int key, t_all *all)
{
	if (key == 53)
		exit (0);
	if (key == 2)
		all->plr.d = 1;
	if (key == 1)
		all->plr.s = 1;
	if (key == 0)
		all->plr.a = 1;
	if (key == 13)
		all->plr.w = 1;
	if (key == 123)
		all->plr.left = 1;
	if (key == 124)
		all->plr.right = 1;
	return (1);
}

int	key_release(int key, t_all *all)
{
	if (key == 53)
		exit (0);
	if (key == 2)
		all->plr.d = 0;
	if (key == 1)
		all->plr.s = 0;
	if (key == 0)
		all->plr.a = 0;
	if (key == 13)
		all->plr.w = 0;
	if (key == 123)
		all->plr.left = 0;
	if (key == 124)
		all->plr.right = 0;
	return (1);
}

void	move_left(t_win *mlx, t_all *all)
{
	if (all->plr.left)
	{
		mlx->olddirx = mlx->dirx;
		mlx->dirx = mlx->dirx * cos(-mlx->rotspeed)
			- mlx->diry * sin(-mlx->rotspeed);
		mlx->diry = mlx->olddirx * sin(-mlx->rotspeed)
			+ mlx->diry * cos(-mlx->rotspeed);
		mlx->oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(-mlx->rotspeed)
			- mlx->planeY * sin(-mlx->rotspeed);
		mlx->planeY = mlx->oldPlaneX * sin(-mlx->rotspeed)
			+ mlx->planeY * cos(-mlx->rotspeed);
	}
	if (all->plr.a)
	{
		mlx->posx -= mlx->planeX * 1.1 * mlx->movespeed;
		mlx->posy -= mlx->dirx * 1.1 * mlx->movespeed;
		if (all->flags.map[(int)(mlx->posy)][(int)(mlx->posx)] == '1')
		{
			mlx->posx += mlx->planeX * 1.1 * mlx->movespeed;
			mlx->posy += mlx->dirx * 1.1 * mlx->movespeed;
		}
	}
}

void	move_right(t_win *mlx, t_all *all)
{
	if (all->plr.d)
	{
		mlx->posx += mlx->planeX * 1.1 * mlx->movespeed;
		mlx->posy += mlx->dirx * 1.1 * mlx->movespeed;
		if (all->flags.map[(int)(mlx->posy)][(int)(mlx->posx)] == '1')
		{
			mlx->posx -= mlx->planeX * 1.1 * mlx->movespeed;
			mlx->posy -= mlx->dirx * 1.1 * mlx->movespeed;
		}
	}
	if (all->plr.right)
	{
		mlx->olddirx = mlx->dirx;
		mlx->dirx = mlx->dirx * cos(mlx->rotspeed)
			- mlx->diry * sin(mlx->rotspeed);
		mlx->diry = mlx->olddirx * sin(mlx->rotspeed)
			+ mlx->diry * cos(mlx->rotspeed);
		mlx->oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(mlx->rotspeed)
			- mlx->planeY * sin(mlx->rotspeed);
		mlx->planeY = mlx->oldPlaneX * sin(mlx->rotspeed)
			+ mlx->planeY * cos(mlx->rotspeed);
	}
}

void	player_move(t_all *all)
{
	if (all->plr.left || all->plr.a)
		move_left(&all->mlx, all);
	if (all->plr.d || all->plr.right)
		move_right(&all->mlx, all);
	if (all->plr.w)
	{
		all->mlx.posx += all->mlx.dirx * 1.1 * all->mlx.movespeed;
		all->mlx.posy += all->mlx.diry * 1.1 * all->mlx.movespeed;
		if (all->flags.map[(int)(all->mlx.posy)][(int)(all->mlx.posx)] == '1')
		{
			all->mlx.posx -= all->mlx.dirx * 1.1 * all->mlx.movespeed;
			all->mlx.posy -= all->mlx.diry * 1.1 * all->mlx.movespeed;
		}
	}
	if (all->plr.s)
	{
		all->mlx.posx -= all->mlx.dirx * 1.1 * all->mlx.movespeed;
		all->mlx.posy -= all->mlx.diry * 1.1 * all->mlx.movespeed;
		if (all->flags.map[(int)(all->mlx.posy)][(int)(all->mlx.posx)] == '1')
		{
			all->mlx.posx += all->mlx.dirx * 1.1 * all->mlx.movespeed;
			all->mlx.posy += all->mlx.diry * 1.1 * all->mlx.movespeed;
		}
	}
}
