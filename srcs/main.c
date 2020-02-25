/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:04:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/25 19:29:22 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_legend(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, PEAK_COLOR, " ^");
	mlx_string_put(fdf->mlx, fdf->win, 10, 15, PEAK_COLOR, "< > Move");
	mlx_string_put(fdf->mlx, fdf->win, 10, 20, PEAK_COLOR, " v");
	mlx_string_put(fdf->mlx, fdf->win, 10, 40, PEAK_COLOR, "ESC Close");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, PEAK_COLOR, "+ - Zoom");
	mlx_string_put(fdf->mlx, fdf->win, 10, 80, PEAK_COLOR, "w s Height");
	mlx_string_put(fdf->mlx, fdf->win, 10, 100, PEAK_COLOR, "q a Rotate");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, PEAK_COLOR, "SPACE Persp");
}

void	ini_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, WIN_NAME);
	fdf->color = PEAK_COLOR;
	fdf->inc_z = 3;
	fdf->mul_x = 1;
}

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->persp % 2 == 0)
	{
		draw_v(fdf);
		draw_h(fdf);
	}
	else
	{
		draw_vgrid(fdf);
		draw_hgrid(fdf);
	}
	write_legend(fdf);
}

void	reset_perspective(t_fdf *fdf)
{
	fdf->dist_x = (WIN_W / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + \
		pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
	fdf->dist_y = (WIN_H / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + \
		pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
	fdf->init_x = (WIN_W / 3);
	fdf->init_y = (WIN_H / 10);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		ft_putendl("usage ./fd [map_file]");
	else
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			ft_puterr("ERROR: Memory Allocation error for fdf.", 1);
		ini_fdf(fdf);
		read_file(fdf, av[1]);
		reset_perspective(fdf);
		redraw(fdf);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
