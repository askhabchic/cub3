/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:23:26 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/22 22:38:57 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	start_end_cordinate(t_all *all, t_spr *sp)
{
	sp->spr_h = (int)fabs(all->flags.ry / sp->trans_y);
	sp->sp_starty = all->flags.ry / 2 - sp->spr_h / 2;
	if (sp->sp_starty < 0)
		sp->sp_starty = 0;
	sp->sp_endy = sp->spr_h / 2 + all->flags.ry / 2;
	if (sp->sp_endy >= all->flags.ry)
		sp->sp_endy = all->flags.ry;
	sp->spr_w = (int)fabs(all->flags.ry / sp->trans_y);
	sp->sp_startx = sp->screenx - sp->spr_w / 2;
	if (sp->sp_startx < 0)
		sp->sp_startx = 0;
	sp->sp_endx = sp->screenx + sp->spr_w / 2;
	if (sp->sp_endx >= all->flags.rx)
		sp->sp_endx = all->flags.rx;
	sp->stripe = sp->sp_startx;
}

void	write_color(t_all *all, t_spr *sp, int y)
{
	int	d;

	d = y * 256 - all->flags.ry * 128 + sp->spr_h * 128;
	sp->tex_y = ((d * all->tx.sp.texheight) / sp->spr_h) / 256;
	sp->clr = *(int *)(all->tx.sp.addr + (sp->tex_y
				* all->tx.sp.l_len + sp->tex_x * (all->tx.sp.bpp / 8)));
}

void	draw_spr_pix(t_all *all, t_spr *sp)
{
	int	y;

	while (sp->stripe < sp->sp_endx)
	{
		sp->tex_x = (int)((256 * (sp->stripe - (-sp->spr_w / 2
							+ sp->screenx)) * all->tx.sp.texwidth
					/ sp->spr_w) / 256);
		if (sp->trans_y > 0.2 && sp->stripe > 0 && sp->stripe < all->flags.rx
			&& sp->trans_y < all->mlx.zBuffer[sp->stripe])
		{
			y = sp->sp_starty;
			while (y < sp->sp_endy)
			{
				write_color(all, sp, y);
				if ((sp->clr & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&all->img, sp->stripe, y, sp->clr);
				y++;
			}
		}
		sp->stripe++;
	}
}

void	calc_spr(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->spr.sp_num)
	{
		all->spr.spr_x = all->spr.arr[i].x - all->mlx.posx;
		all->spr.spr_y = all->spr.arr[i].y - all->mlx.posy;
		all->spr.inDet = 1.0 / (all->mlx.planeX * all->mlx.diry
				- all->mlx.dirx * all->mlx.planeY);
		all->spr.trans_x = all->spr.inDet * (all->mlx.diry * all->spr.spr_x
				- all->mlx.dirx * all->spr.spr_y);
		all->spr.trans_y = all->spr.inDet * (all->mlx.planeX * all->spr.spr_y
				- all->mlx.planeY * all->spr.spr_x);
		all->spr.screenx = (int)(all->flags.rx / 2)
			*(1 + all->spr.trans_x / all->spr.trans_y);
		start_end_cordinate(all, &all->spr);
		draw_spr_pix(all, &all->spr);
		i++;
	}
}

void	draw_sprite(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->spr.sp_num)
	{
		all->spr.arr[i].dist = (all->mlx.posx - all->spr.arr[i].x)
			* (all->mlx.posx - all->spr.arr[i].x)
			+ (all->mlx.posy - all->spr.arr[i].y)
			* (all->mlx.posy - all->spr.arr[i].y);
		i++;
	}
	sort_spr(all);
	calc_spr(all);
}
