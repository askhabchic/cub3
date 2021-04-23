/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:58:20 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/21 20:40:04 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_bitmap(t_all *all)
{
	uint32_t	size;

	size = all->flags.rx * all->flags.ry * 4;
	all->bitmap.fileheader.signature[0] = 'B';
	all->bitmap.fileheader.signature[1] = 'M';
	all->bitmap.fileheader.filesize = size + 54;
	all->bitmap.fileheader.fileoffset_to_pixelarray = 54;
	all->bitmap.fileheader.reserved = 0;
	all->bitmap.bitmapinfoheader.dibheadersize = sizeof(t_bitmapinfoheader);
	all->bitmap.bitmapinfoheader.width = all->flags.rx;
	all->bitmap.bitmapinfoheader.height = -all->flags.ry;
	all->bitmap.bitmapinfoheader.planes = 1;
	all->bitmap.bitmapinfoheader.bitsperpixel = all->img.bpp;
	all->bitmap.bitmapinfoheader.compression = 0;
	all->bitmap.bitmapinfoheader.imagesize = size;
	all->bitmap.bitmapinfoheader.xpixelpermeter = 0;
	all->bitmap.bitmapinfoheader.ypixelpermeter = 0;
	all->bitmap.bitmapinfoheader.numcolorspallette = 0;
	all->bitmap.bitmapinfoheader.mostimpcolor = 0;
}

void	write_bmp(t_all *all, int fd)
{
	write(fd, &all->bitmap.fileheader.signature, sizeof(char) * 2);
	write(fd, &all->bitmap.fileheader.filesize, sizeof(int));
	write(fd, &all->bitmap.fileheader.reserved, sizeof(int));
	write(fd, &all->bitmap.fileheader.fileoffset_to_pixelarray, sizeof(int));
	if (!write(fd, &all->bitmap.bitmapinfoheader, sizeof(t_bitmapinfoheader)))
		error("Error: coudn't write .bmp file");
	if (!write(fd, all->img.addr, all->bitmap.bitmapinfoheader.imagesize))
		error("Error: coudn't write .bmp file");
	printf("%s\n", all->img.addr);
}

void	make_screenshot(t_all *all)
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (!fd)
		error("Error: coudn't create .bmp file");
	init_bitmap(all);
	write_bmp(all, fd);
	close(fd);
	exit (0);
}

void	screenshot(t_all *all)
{
	all->img.addr = malloc(all->flags.rx * all->flags.ry * sizeof(int));
	all->img.bpp = 32;
	all->img.line_len = all->flags.rx * 4;
	fill_fl(all);
	fill_ceil(all);
	draw_map(all);
	printf("%s\n", all->img.addr);
	make_screenshot(all);
}
