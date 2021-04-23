/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:50:59 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/23 18:53:55 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	map_isolation(t_all *all, int x, int y, int y_max)
{
	if (y < 0 || x < 0 || y >= y_max)
		error("Error: invalid map");
	if (all->flags.map[y][x] == ' ' || all->flags.map[y][x] == '\0')
		error("Error: invalid map");
	if (all->flags.map[y][x] == '1' || all->flags.map[y][x] == '.'
		|| all->flags.map[y][x] == 'x')
		return (1);
	if (all->flags.map[y][x] == '0')
		all->flags.map[y][x] = '.';
	else if (all->flags.map[y][x] == '2')
		all->flags.map[y][x] = 'x';
	return (map_isolation(all, x - 1, y, y_max)
		&& map_isolation(all, x + 1, y, y_max)
		&& map_isolation(all, x, y - 1, y_max)
		&& map_isolation(all, x, y + 1, y_max)
		&& map_isolation(all, x - 1, y + 1, y_max)
		&& map_isolation(all, x + 1, y + 1, y_max)
		&& map_isolation(all, x - 1, y - 1, y_max)
		&& map_isolation(all, x + 1, y - 1, y_max));
}

// void	check_map_isolation(t_all *all)
// {
	
// }

void	read_lines(t_all *all, char *line)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (error_gnl(all, &line) > 0)
	{
		i++;
		parser(line, all);
		if (all->flags.maphere == 1)
		{
			all->flags.map[n] = malloc(all->flags.maxlen + 1);
			add_spaces(all, n, line);
			n++;
		}
		free(line);
	}
	parser(line, all);
	all->flags.map[n] = malloc(all->flags.maxlen + 1);
	add_spaces(all, n, line);
	n++;
	all->flags.map[n] = NULL;
	free(line);
}

void	read_map(t_all *all)
{
	int		c;
	char	*line;

	all->flags.map_fd = open(all->flags.map_name, O_RDWR);
	if (all->flags.map_fd < 0)
		error("Error: map can't be opened");
	while (error_gnl(all, &line) > 0)
	{
		all->flags.nlines++;
		check_len(all, line);
		free (line);
	}
	free (line);
	c = close(all->flags.map_fd);
	all->flags.map_fd = open(all->flags.map_name, O_RDWR);
	if (all->flags.map_fd < 0)
		error("Error: map can't be opened");
	all->flags.map = malloc(sizeof(char *) * (all->flags.nlines
				- all->flags.maplines + 3));
	read_lines(all, line);
	plr_search(all);
	calc_height(all);
	map_isolation(all, all->plr.x, all->plr.y, all->flags.nlines);
}

void	check_argc(t_all *all, int argc, char **argv)
{
	int		i;

	i = ft_strlen(argv[1]);
	if (argc == 2 || argc == 3)
	{
		if (ft_strnstr(argv[1], ".cub", i))
			all->flags.map_name = argv[1];
		else
			error("Error: invalid argument");
		if (argc == 3)
		{
			if ((ft_strlen(argv[2]) == 6)
				&& (ft_strncmp(argv[2], "--save", 7) == 0))
				all->flags.save = 1;
			else
				error("Error: invalid argument");
		}
	}
	else
		error("Error: invalid numbers of arguments");
}

int	main(int argc, char **argv)
{
	t_all	all;

	map_init(&all);
	plr_init(&all);
	check_argc(&all, argc, argv);
	read_map(&all);
	all.mlx.mlx = mlx_init();
	get_tex_addr(&all);
	all.mlx.posx = all.plr.x;
	all.mlx.posy = all.plr.y;
	all.mlx.movespeed = 0.08;
	all.mlx.rotspeed = 0.03;
	if (all.flags.save == 1)
		screenshot(&all);
	else
		raicasting(&all);
	return (0);
}
