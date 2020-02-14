/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:54:31 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/14 17:21:35 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_hgrid(t_fdf *fdf)
{
	int new_x;
	int new_z;
	int new_y;

	fdf->index_y = 0;
	fdf->y0 = INIT_Y + fdf->distance + fdf->count_up;
	fdf->x0 = INIT_X + fdf->distance + fdf->count_side;
	fdf->x = fdf->x0;
	while (fdf->index_y < fdf->lines)
	{
		fdf->index_x = 0;
		fdf->y1 = fdf->y0;
		fdf->x0 = fdf->x;
		while (fdf->index_x < fdf->length)
		{
			chose_color(fdf);
			if (fdf->index_x != fdf->length - 1)
				fdf->x1 = fdf->x0 + fdf->distance;
			new_x = 
			draw_line(fdf);
			fdf->x0 = fdf->x1;
			fdf->index_x++;
		}
		fdf->index_y++;
		fdf->y0 = fdf->y0 + fdf->distance;
	}
}

void	draw_vgrid(t_fdf *fdf)
{
	fdf->index_x = 0;
	fdf->y0 = INIT_Y + fdf->distance + fdf->count_up;
	fdf->x0 = INIT_X + fdf->distance + fdf->count_side;
	fdf->y = fdf->y0;
	while (fdf->index_x < fdf->length)
	{
		fdf->index_y = 0;
		fdf->x1 = fdf->x0;
		fdf->y0 = fdf->y;
		while (fdf->index_y < fdf->lines)
		{
			chose_color(fdf);
			if (fdf->index_y != fdf->lines - 1)
				fdf->y1 = fdf->y0 + fdf->distance;
			draw_line(fdf);
			fdf->y0 = fdf->y1;
			fdf->index_y++;
		}
		fdf->index_x++;
		fdf->x0 = fdf->x0 + fdf->distance;
	}
}

void	chose_color(t_fdf *fdf)
{
	if (fdf->y0 == fdf->y1)
	{
		if (fdf->index_x != fdf->length - 1)
		{
			if (fdf->map[fdf->index_y][fdf->index_x] != 0 && 
				fdf->map[fdf->index_y][fdf->index_x + 1] != 0)
				fdf->color = PEAK_COLOR;
			else
				fdf->color = LINE_COLOR;
		}
	}
	else if (fdf->x0 == fdf->x1)
	{
		if (fdf->index_y != fdf->lines - 1)
		{
			if (fdf->map[fdf->index_y][fdf->index_x] != 0 && 
				fdf->map[fdf->index_y + 1][fdf->index_x] != 0)
				fdf->color = PEAK_COLOR;
			else
				fdf->color = LINE_COLOR;
		}
	}
}

/* int		flash_x(t_fdf *fdf)
{

	return(INIT_X - (fdf->distance * fdf->index_y) + (fdf->distance * fdf->index_x));
}

int		flash_y(t_fdf *fdf)
{
	//if (fdf->map[fdf->index_y][fdf->index_x] > 30000)
		//fdf->map[fdf->index_y][fdf->index_x] = 30000;
	//if (fdf->map[fdf->index_y][fdf->index_x] < -30000)
		//fdf->map[fdf->index_y][fdf->index_x] = -30000;
	return(INIT_Y + (fdf->distance * fdf->index_x) + (fdf->distance * fdf->index_y) - (fdf->map[fdf->index_y][fdf->index_x] * 2));
}

void	draw_h(t_fdf *fdf)
{
	fdf->index_y = 0;
	while (fdf->index_y < fdf->lines)
	{
		fdf->index_x = 0;
		if (fdf->index_x < fdf->length - 1)
		{
			fdf->x0 = flash_x(fdf);
			fdf->y0 = flash_y(fdf);
			fdf->index_x++;
			fdf->x1 = flash_x(fdf);
			fdf->y1 = flash_y(fdf);
			draw_line(fdf);
		}
		fdf->index_y++;
	}
}

void	draw_v(t_fdf *fdf)
{
	fdf->index_y = 0;
	while (fdf->index_y < (fdf->lines - 1))
	{
		fdf->index_x = 0;
		if (fdf->index_x < fdf->length)
		{
			fdf->x0 = flash_x(fdf);
			fdf->y0 = flash_y(fdf);
			fdf->index_y++;
			fdf->x1 = flash_x(fdf);
			fdf->y1 = flash_y(fdf);
			fdf->index_y--;
			draw_line(fdf);
			fdf->index_x++;
		}
		fdf->index_y++;
	}
} */