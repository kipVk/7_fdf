/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/30 17:08:32 by rcenamor         ###   ########.fr       */
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
	int			**map;
}				t_fdf;

/*
** Macros
*/

# define WIN_H 500
# define WIN_W 818
# define LINE_COLOR 0x000000
# define BG_COLOR 0xFFFFFF
# define WIN_NAME "FDF"

/*
** Draw
*/

void			draw_line(t_fdf *fdf);
void			draw_down(t_fdf *fdf);
void			draw_up(t_fdf *fdf);
void			paint_background(t_fdf *fdf);

/*
** Test
*/

void			test_line(t_fdf *fdf);

/*
** Read
*/

void	read_file(int fd, t_fdf *fdf);

#endif
