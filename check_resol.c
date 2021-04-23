/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:59:03 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/21 20:34:15 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_overflow(t_all *all)
{
	int		width;
	int		height;

	if (all->flags.save == 1)
	{
		width = 16000;
		height = 13000;
		if (all->flags.rx > width || all->flags.ry >height)
			error("Resolution is too large. There isn't enough memory");
	}
	else
		mlx_get_screen_size(&width, &height);
	if (all->flags.overx == 1 || all->flags.rx > width)
		all->flags.rx = width;
	if (all->flags.overx == 1 || all->flags.ry > height)
		all->flags.ry = height;
}

int	resol_error(char *str, int i, t_all *all)
{
	if (str[i] == '\0' || str[i] == '\n')
	{
		if (all->flags.rx >= 50 && all->flags.ry >= 50)
			return (1);
		else
			error("Error: invalid value of resolution arguments");
		return (1);
	}	
	else
	{
		if (ft_isalpha(str[i]) == 1)
			error("Error: invalid value of resolution arguments");
		else if (ft_isascii(str[i] == 1))
			error("Error: too many arguments of resolution");
	}
	return (0);
}

int	write_resol(char *str, t_all *all)
{
	int		k;
	int		t;

	k = 0;
	t = k;
	all->flags.rx = ft_atoi(str);
	while (ft_isdigit(str[k]) == 1)
		k++;
	if (k - t > 9)
		all->flags.overx = 1;
	while (str[k] == ' ')
		k++;
	if (ft_isdigit(str[k] == 0))
		error("Error: invalid value of resolution arguments");
	t = k;
	all->flags.ry = ft_atoi(&str[k]);
	while (ft_isdigit(str[k]) == 1)
		k++;
	if (k - t > 9)
		all->flags.overy = 1;
	check_overflow(all);
	return (k);
}

int	skip_space(char *arr, int i)
{
	while (arr[i] == ' ')
		i++;
	return (i);
}

void	check_resol(char *arr, t_all *all)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = ft_strlen(arr);
	if (all->flags.rx == -1 && all->flags.ry == -1)
	{
		i = i + skip_space(arr, i);
		if (arr[i++] == 'R')
			i = skip_space(arr, i);
		if (ft_isdigit(arr[i]) == 1)
		{
			str = ft_substr(arr, i, (n - i));
			i = write_resol(str, all);
			while (str[i] == ' ')
				i++;
			resol_error(str, i, all);
			free(str);
		}
		else
			error("Error: invalid value of resolution arguments");
	}
}
