/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:05:23 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/22 21:08:11 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_comma(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
		{
			while (str[i] != ',' && str[i] != '\0')
			{
				i++;
				if (str[i] == ',')
				{
					n++;
					i++;
					if (str[i] == ',')
						error("Error: invalid input for color");
				}
			}
		}
		else
			error("Error: invalid input for color");
	}
	if (n != 2)
		return (0);
	else
		return (1);
}

int	check_color_value(int *rgb)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			error("Error: invalid value of color");
		i++;
	}
	return (0);
}

void	check_array(char *str)
{
	int		i;
	int		n;
	int		k;

	n = 0;
	i = 0;
	k = 0;
	if (str == NULL)
		error("Error: invalid color");
	while (n < 3)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			while (ft_isdigit(str[i]) == 1)
				i++;
			k++;
		}
		while (str[i] == ',' || str[i] == ' ')
			i++;
		n++;
	}
	if (k != 3)
		error("Error: invalid arguments for RGB-color");
	if (str[i] != '\0')
		error("Error: invalid arguments for RGB-color");
}

// void	check_valid_rgb(char **arr)
// {
	
// }

int	write_rgb_color(char *arr, char *str)
{
	int		len;
	int		rgb[3];
	char	*string;
	char	**array;
	int		value;

	array = NULL;
	string = ft_strtrim(arr, str);
	if (check_comma(string) == 1)
		array = ft_split(string, ',');
	else
		error("Error: invalid type of data");
	check_array(string);
	len = ft_strlen(*array);
	// check_valid_rgb(array);
	rgb[0] = ft_atoi(array[0]);
	rgb[1] = ft_atoi(array[1]);
	rgb[2] = ft_atoi(array[2]);
	check_color_value(rgb);
	value = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	while (len--)
		free (array[len]);
	free (array);
	free (string);
	return (value);
}

void	check_c(char *arr, t_all *all)
{
	int		i;

	i = 0;
	while (arr[i] == ' ')
		i++;
	if (arr[i] == 'C' && all->flags.ceil == -1)
		all->flags.ceil = write_rgb_color(arr, "C ");
	else if (arr[i] == 'F' && all->flags.flo == -1)
		all->flags.flo = write_rgb_color(arr, "F ");
	else
		error("Error: arguments are repeated");
}
