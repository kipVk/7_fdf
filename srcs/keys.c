/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:39:15 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 19:50:04 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Changes values on fdf to simulate zooming in and out.
*/

int		zoom(t_fdf *fdf, int key)
{
	if (key == ZOOM_I)
	{
		fdf->dist_x *= 2;
		fdf->dist_y *= 2;
		fdf->inc_z *= 2;
		fdf->p_max_z *= 2;
		fdf->n_max_z *= -2;
	}
	if (key == ZOOM_O)
	{
		if ((fdf->dist_x / 2 == 0) || (fdf->dist_y / 2 == 0) || \
			(fdf->inc_z / 2 == 0))
			return (0);
		fdf->dist_x /= 2;
		fdf->dist_y /= 2;
		fdf->inc_z /= 2;
		fdf->p_max_z = ((fdf->p_max_z / 2 == 0) ? 1 : \
			(fdf->p_max_z /= 2));
		fdf->n_max_z = ((fdf->n_max_z / -2 == 0) ? -1 : \
			(fdf->n_max_z /= -2));
	}
	return (0);
}

/*
** Changes values on fdf to change perspectives between conic and isometric.
*/

void	space(t_fdf *fdf)
{
	fdf->persp++;
	fdf->persp = (fdf->persp > 2) ? 0 : fdf->persp;
	if (fdf->persp == 0 || fdf->persp == 2)
		reset_perspective(fdf);
	else
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
}

/*
** Changes values on fdf to simulate rotation on the deep plane.
*/

void	rotate(t_fdf *fdf, int key)
{
	if (key == Q_K)
	{
		fdf->dist_x -= SIDE_VALUE * 0.2;
		fdf->dist_y -= SIDE_VALUE * 0.2;
		fdf->init_x += SIDE_VALUE;
		fdf->init_y += SIDE_VALUE;
	}
	if (key == A_K)
	{
		fdf->dist_x += SIDE_VALUE * 0.2;
		fdf->dist_y += SIDE_VALUE * 0.2;
		fdf->init_x -= SIDE_VALUE;
		fdf->init_y -= SIDE_VALUE;
	}
}

/*
** Changes values on fdf to simulate movement on the screen plane.
*/

void	move(t_fdf *fdf, int key)
{
	if (key == UP_A)
		fdf->count_up -= UP_VALUE;
	if (key == DOWN_A)
		fdf->count_up += UP_VALUE;
	if (key == RIGHT_A)
		fdf->count_side += SIDE_VALUE;
	if (key == LEFT_A)
		fdf->count_side -= SIDE_VALUE;
}

/*
** Associates keys and functions.
*/

int		key_press(int key, t_fdf *fdf)
{
	if (key == ESC_K)
		exit(0);
	if (key == UP_A || key == DOWN_A || key == RIGHT_A || key == LEFT_A)
		move(fdf, key);
	if (key == Q_K || key == A_K)
		rotate(fdf, key);
	if (key == W_K)
		fdf->inc_z += 1;
	if (key == S_K)
		fdf->inc_z -= 1;
	if (key == SPC_K)
		space(fdf);
	if (key == ZOOM_I || key == ZOOM_O)
		zoom(fdf, key);
	redraw(fdf);
	return (0);
}
