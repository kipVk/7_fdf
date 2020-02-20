/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:54:31 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/20 13:35:43 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	return (fdf->init_x + fdf->dist_x + fdf->count_side - (fdf->dist_x * y) + (fdf->dist_x * x));
}

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	return (fdf->init_y + fdf->dist_y + fdf->count_up + (fdf->dist_y * x) + ((fdf->dist_y * y)) - (z));
}

void	draw_h(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < (fdf->lines - 1))
	{
		j = 0;
		while (j < fdf->length && (fdf->length - j) > 0)
		{
			fdf->x0 = coord_x(fdf, j, i);
			fdf->y0 = coord_y(fdf, j, i, fdf->map[i][j] * fdf->inc_z);
			fdf->x1 = coord_x(fdf, j, i + 1);
			fdf->y1 = coord_y(fdf, j, i + 1, fdf->map[i + 1][j] * fdf->inc_z);
			//chose_color(fdf, j, i);
			draw_line(fdf, j, i, fdf->inc_z);
			j++;
		}
		i++;
	}
}

void	draw_v(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < fdf->lines)
	{
		j = 0;
		while (j < (fdf->length - 1))
		{
			fdf->x0 = coord_x(fdf, j, i);
			fdf->y0 = coord_y(fdf, j, i, fdf->map[i][j] * fdf->inc_z);
			j++;
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->map[i][j] * fdf->inc_z);
			//chose_color(fdf, j, i);
			draw_line(fdf, j, i, fdf->inc_z);
		}
		i++;
	}
}

void	draw_hgrid(t_fdf *fdf)
{
	fdf->index_y = 0;
	fdf->y0 = INIT_Y + fdf->count_up;
	fdf->x0 = INIT_X + fdf->count_side;
	fdf->x = fdf->x0;
	while (fdf->index_y < fdf->lines)
	{
		fdf->index_x = 0;
		fdf->y1 = fdf->y0;
		fdf->x0 = fdf->x;
		while (fdf->index_x < fdf->length)
		{
			//chose_color(fdf, fdf->index_x, fdf->index_y);
			if (fdf->index_x != fdf->length - 1)
				fdf->x1 = fdf->x0 + fdf->dist_x;
			draw_line(fdf, fdf->index_x, fdf->index_y, fdf->inc_z);
			fdf->x0 = fdf->x1;
			fdf->index_x++;
		}
		fdf->index_y++;
		fdf->y0 = fdf->y0 + fdf->dist_x;
	}
}

void	draw_vgrid(t_fdf *fdf)
{
	fdf->index_x = 0;
	fdf->y0 = INIT_Y + fdf->count_up;
	fdf->x0 = INIT_X + fdf->count_side;
	fdf->y = fdf->y0;
	while (fdf->index_x < fdf->length)
	{
		fdf->index_y = 0;
		fdf->x1 = fdf->x0;
		fdf->y0 = fdf->y;
		while (fdf->index_y < fdf->lines)
		{
			//chose_color(fdf, fdf->index_x, fdf->index_y);
			if (fdf->index_y != fdf->lines - 1)
				fdf->y1 = fdf->y0 + fdf->dist_x;
			draw_line(fdf, fdf->index_x, fdf->index_y, fdf->inc_z);
			fdf->y0 = fdf->y1;
			fdf->index_y++;
		}
		fdf->index_x++;
		fdf->x0 = fdf->x0 + fdf->dist_x;
	}
}

void	chose_color(t_fdf *fdf, int x, int y, double z)
{
	if ((fdf->map[y][x] * z) > 0)
		fdf->color = PEAK_COLOR;
	else if ((fdf->map[y][x] * z) < 0)
		fdf->color = VALLEY_COLOR;
	else
		fdf->color = LINE_COLOR;
}

/* void	chose_color(t_fdf *fdf)
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
} */
