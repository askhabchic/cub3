/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:33:53 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/22 18:57:45 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_tex_addr(t_all *all)
{
	write_texture(all, all->flags.no, &all->tx.no);
	write_texture(all, all->flags.so, &all->tx.so);
	write_texture(all, all->flags.sp, &all->tx.sp);
	write_texture(all, all->flags.we, &all->tx.we);
	write_texture(all, all->flags.ea, &all->tx.ea);
}

void	check_texture(char *arr, t_all *all)
{
	if (ft_strstr(arr, "NO ") != 0)
		all->flags.no = write_texture_path(arr, 3, all->flags.no);
	else if (ft_strstr(arr, "SO ") != 0)
		all->flags.so = write_texture_path(arr, 3, all->flags.so);
	else if (ft_strstr(arr, "WE ") != 0)
		all->flags.we = write_texture_path(arr, 3, all->flags.we);
	else if (ft_strstr(arr, "EA ") != 0)
		all->flags.ea = write_texture_path(arr, 3, all->flags.ea);
	else if (ft_strstr(arr, "S ") != 0 && ft_strstr(arr, "O ") == 0)
		all->flags.sp = write_texture_path(arr, 2, all->flags.sp);
	else
		error("Error: missing arguments or data passed incorrectly");
}
