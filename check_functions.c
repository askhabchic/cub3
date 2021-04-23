/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:51:25 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/20 22:44:33 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sort_spr(t_all *all)
{
	t_sp	tmp;
	int		i;
	int		j;

	i = 0;
	while (i++ < all->spr.sp_num)
	{
		j = 0;
		while (j < all->spr.sp_num - 1)
		{
			if (all->spr.arr[j].dist < all->spr.arr[j + 1].dist)
			{
				tmp.dist = all->spr.arr[j].dist;
				tmp.x = all->spr.arr[j].x;
				tmp.y = all->spr.arr[j].y;
				all->spr.arr[j].dist = all->spr.arr[j + 1].dist;
				all->spr.arr[j].x = all->spr.arr[j + 1].x;
				all->spr.arr[j].y = all->spr.arr[j + 1].y;
				all->spr.arr[j + 1].dist = tmp.dist;
				all->spr.arr[j + 1].x = tmp.x;
				all->spr.arr[j + 1].y = tmp.y;
			}
			j++;
		}
	}
}

int	check_flags(t_all *all)
{
	if (all->flags.rx != -1 && all->flags.rx != -1 && all->flags.no != NULL
		&& all->flags.so != NULL && all->flags.we != NULL
		&& all->flags.ea != NULL && all->flags.sp != NULL
		&& all->flags.flo != -1 && all->flags.ceil != -1)
		return (1);
	else
		error("Error: some parameters are missing");
	return (0);
}

void	check_len(t_all *all, char *line)
{
	int		i;

	i = 0;
	all->flags.len = 0;
	if (line[i] == '1' || line[i] == ' ')
	{
		if (all->flags.maplines == 0)
			all->flags.maplines = all->flags.nlines;
		while (line[all->flags.len] != '\0')
			all->flags.len++;
		if (all->flags.maxlen == 0 || all->flags.len > all->flags.maxlen)
			all->flags.maxlen = all->flags.len;
	}
}

void	add_spaces(t_all *all, int n, char *line)
{
	int		i;
	int		dif;

	i = 0;
	all->flags.len = ft_strlen(line);
	dif = all->flags.maxlen - all->flags.len;
	all->flags.map[n] = ft_memcpy(all->flags.map[n], line, all->flags.len);
	while (dif > 0)
	{
		all->flags.map[n][all->flags.len] = ' ';
		all->flags.len++;
		dif--;
	}
	all->flags.map[n][all->flags.len] = '\0';
}

void	calc_height(t_all *all)
{
	int		i;

	i = 0;
	all->flags.nlines = 0;
	while (all->flags.map[i] != NULL)
	{
		all->flags.nlines += 1;
		i++;
	}
}
