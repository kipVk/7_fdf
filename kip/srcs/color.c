/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:57:16 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 20:03:15 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Selects the color for negative heights
*/

void	color_neg(t_fdf *fdf, int x, int y, double z)
{
	if (z > 0)
	{
		if ((fdf->map[y][x] * z) <= fdf->n_max_z * z / 2)
			fdf->color = D_VALLEY_COLOR;
		else
			fdf->color = VALLEY_COLOR;
	}
	else if (z < 0)
	{
		if ((fdf->map[y][x] * z) >= fdf->n_max_z * z / 2)
			fdf->color = D_PEAK_COLOR;
		else
			fdf->color = PEAK_COLOR;
	}
}

/*
** Selects the color for positive heights
*/

void	color_pos(t_fdf *fdf, int x, int y, double z)
{
	if (z < 0)
	{
		if ((fdf->map[y][x] * z) >= fdf->p_max_z * z / 2)
			fdf->color = VALLEY_COLOR;
		else
			fdf->color = D_VALLEY_COLOR;
	}
	else if (z > 0)
	{
		if ((fdf->map[y][x] * z) >= fdf->p_max_z * z / 2)
			fdf->color = D_PEAK_COLOR;
		else
			fdf->color = PEAK_COLOR;
	}
}

/*
** Selects the color based on the height compared to 0
*/

void	chose_color(t_fdf *fdf, int x, int y, double z)
{
	fdf->color = LINE_COLOR;
	if (fdf->map[y][x] < 0)
		color_neg(fdf, x, y, z);
	else if (fdf->map[y][x] > 0)
		color_pos(fdf, x, y, z);
}
