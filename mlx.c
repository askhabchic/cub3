/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:02:17 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/19 20:39:34 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_tex *tex, char *addr, int x, int y)
{
	char	*dst;
	int		color;

	dst = addr + (y * tex->l_len + x * (tex->bpp / 8));
	color = *(int *)dst;
	return (color);
}

void	raicasting(t_all *all)
{
	all->mlx.win = mlx_new_window(all->mlx.mlx,
			all->flags.rx, all->flags.ry, "cub3d");
	all->img.img = mlx_new_image(all->mlx.mlx, all->flags.rx, all->flags.ry);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
			&all->img.line_len, &all->img.endian);
	mlx_hook(all->mlx.win, 2, 0, &key_press, all);
	mlx_hook(all->mlx.win, 17, 1L << 0, &quit, all);
	mlx_key_hook(all->mlx.win, key_release, all);
	mlx_loop_hook(all->mlx.mlx, &draw, all);
	mlx_loop(all->mlx.mlx);
}
