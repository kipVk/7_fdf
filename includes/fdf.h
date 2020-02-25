/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/25 19:58:51 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# include <stdio.h>

# include <unistd.h>

typedef struct	s_image
{
	char		*data;
	int			size;
	int			endian;
	int			bpp;
}				t_image;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		incx;
	double		incy;
	int			lines;
	int			length;
	int			**map;
	int			color;
	int			index_x;
	int			index_y;
	double		count_up;
	double		count_side;
	double		dist_x;
	double		dist_y;
	double		init_x;
	double		init_y;
	double		inc_z;
	double		mul_x;
	int			persp;
	t_image		image;
}				t_fdf;

/*
** Macros
*/

# define WIN_H 720
# define WIN_W 1280
# define LINE_COLOR 0xd9d9d9
# define BG_COLOR 0x404040
# define PEAK_COLOR 0x4da6ff
# define VALLEY_COLOR 0xffa6ff
# define WIN_NAME "FDF"
# define DISTANCE 25
# define INIT_X WIN_W/5
# define INIT_Y WIN_H/5
# define ESC_K 53
# define RIGHT_A 124
# define LEFT_A 123
# define UP_A 126
# define DOWN_A 125
# define UP_VALUE 4
# define SIDE_VALUE 3
# define ZOOM_O 78
# define ZOOM_I 69
# define W_K 13
# define S_K 1
# define Q_K 12
# define A_K 0
# define SPC_K 49
# define E_K 14
# define D_K 2

/*
** Main
*/

void			write_legend(t_fdf *fdf);
void			ini_fdf(t_fdf *fdf);
void			redraw(t_fdf *fdf);
void			reset_perspective(t_fdf *fdf);

/*
** Read
*/

void			get_map_value(t_fdf *fdf, int row, char *line);
void			read_map(t_fdf *fdf, int fd);
void			read_file(t_fdf *fdf, char *file);

/*
** Draw
*/

void			draw_hgrid(t_fdf *fdf);
void			draw_vgrid(t_fdf *fdf);
void			draw_h(t_fdf *fdf);
void			draw_v(t_fdf *fdf);
void			chose_color(t_fdf *fdf, int x, int y, double inc_z);

/*
** Bresenham
*/

void			draw_line(t_fdf *fdf, int x, int y, double inc_z);
void			draw_down(t_fdf *fdf, int x, int y, double inc_z);
void			draw_up(t_fdf *fdf, int x, int y, double inc_z);
int				coord_x(t_fdf *fdf, int x, int y);
int				coord_y(t_fdf *fdf, int x, int y, int z);

/*
** Keys
*/

int				key_press(int key, t_fdf *fdf);
int				zoom(t_fdf *fdf, int key);
void			space(t_fdf *fdf);
void			rotate(t_fdf *fdf, int key);
void			move(t_fdf *fdf, int key);

#endif
