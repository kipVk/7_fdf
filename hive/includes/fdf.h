/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/03/02 14:18:53 by rcenamor         ###   ########.fr       */
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

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
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
	int			persp;
	double		p_max_z;
	double		n_max_z;
}				t_fdf;

/*
** Macros
*/

# define WIN_H 720
# define WIN_W 1280
# define LINE_COLOR 0xd9d9d9
# define BG_COLOR 0x404040
# define PEAK_COLOR 0x3399ff
# define D_PEAK_COLOR 0xff9966
# define VALLEY_COLOR 0x33cc33
# define D_VALLEY_COLOR 0xff3300
# define WIN_NAME "FDF"
# define ESC_K 53
# define RIGHT_A 124
# define LEFT_A 123
# define UP_A 126
# define DOWN_A 125
# define UP_VALUE 3
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

void			redraw(t_fdf *fdf);

/*
** Init
*/

void			write_legend(t_fdf *fdf);
void			ini_fdf(t_fdf *fdf);
void			init_perspective(t_fdf *fdf);
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

/*
** Bresenham
*/

void			draw_line(t_fdf *fdf);
void			draw_down(t_fdf *fdf);
void			draw_up(t_fdf *fdf);
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

/*
** Color
*/

void			color_neg(t_fdf *fdf, int x, int y, double z);
void			color_pos(t_fdf *fdf, int x, int y, double z);
void			chose_color(t_fdf *fdf, int x, int y, double z);

#endif
