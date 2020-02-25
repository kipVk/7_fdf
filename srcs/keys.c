/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:39:15 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/25 14:51:07 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zoom(t_fdf *fdf, int key)
{
	if (key == ZOOM_I)
	{
		fdf->dist_x *= 2;
		fdf->dist_y *= 2;
		fdf->inc_z *= 2;
	}
	if (key == ZOOM_O)
	{
		if ((fdf->dist_x / 2 == 0) || (fdf->dist_y / 2 == 0) || (fdf->inc_z / 2 == 0)) 
			return(0);
		fdf->dist_x /= 2;
		fdf->dist_y /= 2;
		fdf->inc_z /= 2;
	}
	return (0);
}

void	space(t_fdf *fdf)
{
	fdf->persp++;
		if (fdf->persp % 2 == 0)
		{
			fdf->dist_x = (WIN_W / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
			fdf->dist_y = (WIN_H / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
			fdf->init_x = (WIN_W / 3);
			fdf->init_y = (WIN_H / 10);
		}
		else
		{
			fdf->dist_x = (WIN_W / fdf->length) * 0.6;
			fdf->dist_y = (WIN_H / fdf->lines) * 0.6;
		}
}

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

void	change_height(t_fdf *fdf, int key)
{
	if (key == W_K)
		fdf->inc_z += 1;
	if (key == S_K)
		fdf->inc_z -= 1;
}