/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:04:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/03/02 14:00:23 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Draws the map depending on the selected perspective
*/

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->persp == 1 || fdf->persp == 2)
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

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_putendl("usage ./fd [map_file]");
	else
	{
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(&fdf.mlx, WIN_W, WIN_H, WIN_NAME);
		ini_fdf(&fdf);
		read_file(&fdf, av[1]);
		reset_perspective(&fdf);
		redraw(&fdf);
		mlx_hook(fdf.win, 2, 0, key_press, &fdf);
		mlx_loop(&fdf.mlx);
	}
	return (0);
}
