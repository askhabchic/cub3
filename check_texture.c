/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:01:24 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/22 22:38:11 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	valid_texture_check(char *str)
{
	char	*i;

	i = ft_strnstr(str, ".xpm\0", ft_strlen(str));
	if (i == NULL)
		error("Invalid format of texture");
	else if (str == NULL)
		error("Error: invalid path of texture");
	else
		return (1);
	return (0);
}

void	check_tex_error(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			error("Bad texture path");
	}
}

char	*ft_strcut_n_dup(char *str)
{
	int		len;
	int		i;
	char	*temp;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	len = ft_strlen(str) - i;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	while (j < len)
	{
		if (str[i] == ' ')
			break ;
		else
			temp[j++] = str[i++];
	}
	check_tex_error(str, i);
	temp[j] = '\0';
	return (temp);
}

void	write_texture(t_all *all, char *flags, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(all->mlx.mlx, flags,
			&tex->texwidth, &tex->texheight);
	if (tex->img == NULL || !tex->texwidth || !tex->texheight)
		error("Error: invalid texture or path");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->l_len,
			&tex->endian);
	if (tex->addr == NULL)
		error("Error: invalid texture");
	if (all->tx.sp.texheight > 1968 || all->tx.sp.texwidth > 1968)
		error("Error: invalid texture");
}

char	*write_texture_path(char *arr, int i, char *flags)
{
	char	*str;

	str = NULL;
	if (flags == NULL)
	{
		str = ft_strcut_n_dup(&arr[i]);
		valid_texture_check(str);
	}
	else
		error("Error: arguments are repeated");
	return (str);
}
