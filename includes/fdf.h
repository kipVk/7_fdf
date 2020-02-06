/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/06 18:11:57 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# include <stdio.h>

# include <unistd.h>

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
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
}				t_fdf;

/*
** Macros
*/

# define WIN_H 500
# define WIN_W 818
# define LINE_COLOR 0x000000
# define BG_COLOR 0xFFFFFF
# define PEAK_COLOR 0x33cc33
# define WIN_NAME "FDF"
# define DISTANCE 15
# define INIT_X WIN_W/5
# define INIT_Y WIN_H/5

/*
** Draw
*/

void			draw_line(t_fdf *fdf);
void			draw_down(t_fdf *fdf);
void			draw_up(t_fdf *fdf);
void			paint_background(t_fdf *fdf);
void			draw_hgrid(t_fdf *fdf);
void			draw_vgrid(t_fdf *fdf);
void			chose_color(t_fdf *fdf);

/*
** Test
*/

void			test_line(t_fdf *fdf);

/*
** Read
*/

void	read_file(int fd, t_fdf *fdf);

#endif
