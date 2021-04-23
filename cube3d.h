/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:20:47 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/22 18:57:42 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx/mlx.h"
# include "minilibx_sw/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>

typedef struct s_fileheader
{
	char	signature[2];
	int		filesize;
	int		reserved;
	int		fileoffset_to_pixelarray;
}				t_fileheader;

typedef struct s_bitmapinfoheader
{
	int		dibheadersize;
	int		width;
	int		height;
	short	planes;
	short	bitsperpixel;
	int		compression;
	int		imagesize;
	int		ypixelpermeter;
	int		xpixelpermeter;
	int		numcolorspallette;
	int		mostimpcolor;
}				t_bitmapinfoheader;

typedef struct s_bitmap
{
	t_fileheader		fileheader;
	t_bitmapinfoheader	bitmapinfoheader;
}				t_bitmap;

typedef struct s_sp
{
	double	x;
	double	y;
	double	dist;
	int		order;
}				t_sp;

typedef struct s_spr
{
	int		sp_num;
	int		screenx;
	int		sp_starty;
	int		sp_endy;
	int		sp_startx;
	int		sp_endx;
	int		spr_h;
	int		spr_w;
	int		tex_x;
	int		tex_y;
	int		stripe;
	int		clr;
	t_sp	*arr;
	double	spr_x;
	double	spr_y;
	double	inDet;
	double	trans_x;
	double	trans_y;
}	t_spr;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	raydirx;
	double	raydiry;
	double	planeX;
	double	planeY;
	double	movespeed;
	double	rotspeed;
	double	sidex;
	double	sidey;
	double	deltax;
	double	deltay;
	int		mapx;
	int		mapy;
	int		side;
	int		start;
	int		end;
	int		x;
	int		stepx;
	int		stepy;
	double	olddirx;
	double	oldPlaneX;
	double	perpdist;
	double	*zBuffer;
	int		lineheight;
}	t_win;

typedef struct s_plr
{
	float	x;
	float	y;
	char	dir;
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		found;
}	t_plr;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_map
{
	int		map_fd;
	int		save;
	char	**map;
	char	*map_name;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sp;
	char	*flag_dir;
	int		rx;
	int		overx;
	int		ry;
	int		overy;
	int		ceil;
	int		flo;
	int		nlines;
	int		maplines;
	int		maphere;
	int		len;
	int		maxlen;
	char	*player;
}	t_map;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	int		texwidth;
	int		texheight;
	int		tex_x;
	int		tex_y;
	int		color;
	double	wallx;
	double	step;
	double	texpos;
}	t_tex;

typedef struct s_tx_tex
{
	t_tex	so;
	t_tex	no;
	t_tex	we;
	t_tex	ea;
	t_tex	sp;
}	t_tx_tex;

typedef struct s_lst
{
	t_win		mlx;
	t_plr		plr;
	t_map		flags;
	t_data		img;
	t_tex		tex;
	t_tx_tex	tx;
	t_spr		spr;
	t_bitmap	bitmap;
}	t_all;

char		**make_map(t_list **head, int size);
char		*write_texture_path(char *arr, int i, char *flags);
void		screenshot(t_all *all);
void		map_init(t_all *all);
void		plr_init(t_all *all);
void		check_resol(char *arr, t_all *all);
void		check_texture(char *array, t_all *all);
void		check_c(char *arr, t_all *all);
void		check_f(char *arr, t_all *all);
void		check_sp(char *line, t_all *all);
void		check_map(char *s, t_all *all);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_map(t_all *all);
void		player_move(t_all *all);
void		draw_sq(t_all *all, int x, int y, int color);
void		check_argc(t_all *all, int argc, char **argv);
void		read_map(t_all *all);
void		plr_search(t_all *all);
void		mlx_get_screen_size(int *width, int *height);
void		fill_ceil(t_all *all);
void		fill_fl(t_all *all);
void		make_screenshot(t_all *all);
void		screenshot(t_all *all);
void		error(char *str);
void		draw_sprite(t_all *all);
void		check_side(t_all *all);
void		raicasting(t_all *all);
void		calc_height(t_all *all);
void		add_spaces(t_all *all, int n, char *line);
void		check_len(t_all *all, char *line);
void		sort_spr(t_all *all);
void		write_texture(t_all *all, char *flags, t_tex *tex);
void		get_tex_addr(t_all *all);
int			parser(char *line, t_all *all);
int			valid_texture_check(char *str);
int			int_sep(char *str, t_all *all);
int			resol_error(char *str, int i, t_all *all);
int			write_resol(char *str, t_all *all);
int			draw(t_all *all);
int			key_press(int key, t_all *all);
int			key_release(int key, t_all *all);
int			all_flags(t_all *all);
int			my_mlx_pixel_get(t_tex *tex, char *addr, int x, int y);
int			error_gnl(t_all *all, char **line);
int			check_flags(t_all *all);
int			create_trgb(int t, int r, int g, int b);
int			quit(int key);

#endif
