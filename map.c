/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:40:22 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/21 20:22:23 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_tex(t_all *all, t_tex *tex)
{
	int	y;

	if (all->mlx.side == 0)
		tex->wallx = all->mlx.posy + all->mlx.perpdist * all->mlx.raydiry;
	else
		tex->wallx = all->mlx.posx + all->mlx.perpdist * all->mlx.raydirx;
	tex->wallx -= floor(tex->wallx);
	tex->tex_x = tex->texwidth - 1 - (int)(tex->wallx * (double)tex->texwidth);
	if (all->mlx.side == 0 && all->mlx.raydirx > 0)
		tex->tex_x = tex->texwidth - tex->tex_x - 1;
	if (all->mlx.side == 1 && all->mlx.raydiry < 0)
		tex->tex_x = tex->texwidth - tex->tex_x - 1;
	tex->step = 1.0 * tex->texheight / all->mlx.lineheight;
	tex->texpos = (all->mlx.start - all->flags.ry / 2
			+ all->mlx.lineheight / 2) * tex->step;
	y = all->mlx.start;
	while (y < all->mlx.end)
	{
		tex->tex_y = (int)tex->texpos % (tex->texheight - 1);
		tex->texpos += tex->step;
		tex->color = *(int *)(tex->addr + (tex->tex_y * tex->l_len
					+ tex->tex_x * (tex->bpp / 8)));
		my_mlx_pixel_put(&all->img, all->mlx.x, y, tex->color);
		y++;
	}
}

void	check_side(t_all *all)
{
	if (all->mlx.side == 0)
	{
		if (all->mlx.posx - all->mlx.mapx > 0)
			get_tex(all, &all->tx.we);
		else
			get_tex(all, &all->tx.ea);
	}
	else
	{
		if (all->mlx.posy - all->mlx.mapy > 0)
			get_tex(all, &all->tx.no);
		else
			get_tex(all, &all->tx.so);
	}
}

void	fill_fl(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (y < all->flags.ry)
	{
		x = 0;
		while (x < all->flags.rx)
		{
			my_mlx_pixel_put(&all->img, x, y, all->flags.flo);
			x++;
		}
		y++;
	}
}

void	fill_ceil(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (y < (all->flags.ry / 2))
	{
		x = 0;
		while (x < all->flags.rx)
		{
			my_mlx_pixel_put(&all->img, x, y, all->flags.ceil);
			x++;
		}
		y++;
	}
}

int	draw(t_all *all)
{
	fill_fl(all);
	fill_ceil(all);
	draw_map(all);
	player_move(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	return (1);
}
