/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:59:55 by rcenamor          #+#    #+#             */
/*   Updated: 2020/03/02 15:56:23 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Writes the key options on the screen.
*/

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
	mlx_string_put(fdf->mlx, fdf->win, 10, 140, PEAK_COLOR, "R Reset view");
}

/*
** Initializes fdf with some default values
*/

void	ini_fdf(t_fdf *fdf)
{
	fdf->color = PEAK_COLOR;
	fdf->inc_z = 3;
	fdf->p_max_z = 0;
	fdf->n_max_z = 0;
	fdf->length = 0;
}

/*
** Initializes fdf with the first perspective to show (conic)
*/

void	init_perspective(t_fdf *fdf)
{
	fdf->dist_x = (WIN_W / fdf->length) * 0.8;
	fdf->dist_y = (WIN_H / fdf->lines) * 0.8;
	if (fdf->dist_x > fdf->dist_y)
		fdf->dist_x = fdf->dist_y;
	else
		fdf->dist_y = fdf->dist_x;
	fdf->init_x = (WIN_W / 2) - ((fdf->length * fdf->dist_x) / 2);
	fdf->init_y = (WIN_H / 2) - ((fdf->lines * fdf->dist_y) / 2);
}

/*
** Resets the view to the initial one when pressing R
*/

void	reset_view(t_fdf *fdf)
{
	reset_perspective(fdf);
	fdf->inc_z = 3;
	fdf->count_up = 0;
	fdf->count_side = 0;
	redraw(fdf);
}

/*
** Sets the some values of fdf for the perspective
*/

void	reset_perspective(t_fdf *fdf)
{
	double w;
	double h;

	if (fdf->persp == 1)
	{
		fdf->dist_x = (WIN_W / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + \
			pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
		fdf->dist_y = (WIN_H / ft_sqrt(pow((fdf->lines * cos(M_PI / 3)), 2) + \
			pow((fdf->length * sin(M_PI / 6)), 2))) / 3;
	}
	else if (fdf->persp == 2)
	{
		fdf->dist_x = (WIN_W / fdf->length) * 0.3;
		fdf->dist_y = (WIN_H / fdf->lines) * 0.3;
	}
	w = (fdf->dist_x * cos(M_PI / 6) * fdf->length) + (fdf->dist_y * \
		cos(M_PI / 3) * fdf->lines);
	h = (fdf->dist_x * sin(M_PI / 6) * fdf->length) + (fdf->dist_y * \
		sin(M_PI / 3) * fdf->lines);
	fdf->init_x = ((WIN_W / 2) - ((w / 2)));
	fdf->init_y = ((WIN_H / 2) - ((h / 2)));
	if (fdf->persp == 0)
		init_perspective(fdf);
}
