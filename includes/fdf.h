/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/18 21:27:15 by rcenamor         ###   ########.fr       */
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
	void		*img;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			incx;
	int			incy;
	int			lines;
	int			length;
	int			**map;
	int			color;
	int			index_x;
	int			index_y;
	int			count_up;
	int			count_side;
	int			dist_x;
	int			dist_y;
	int			init_x;
	int			init_y;
	int			inc_z;
}				t_fdf;

/*
** Macros
*/

# define WIN_H 720
# define WIN_W 1280
# define LINE_COLOR 0xd9d9d9
# define BG_COLOR 0x404040
# define PEAK_COLOR 0x4da6ff
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

/*
** Draw
*/

void			draw_hgrid(t_fdf *fdf);
void			draw_vgrid(t_fdf *fdf);
void			chose_color(t_fdf *fdf);
//void			draw_h(t_fdf *fdf);
//void			draw_v(t_fdf *fdf);

/*
** Bresenham
*/

void			draw_line(t_fdf *fdf);
void			draw_down(t_fdf *fdf);
void			draw_up(t_fdf *fdf);

/*
** Main
*/

void			redraw(t_fdf *fdf);

/*
** Read
*/

void			read_file(int fd, t_fdf *fdf);

#endif
