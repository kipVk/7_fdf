/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:54:31 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/07 20:38:58 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

/*
** The gradient increases, the distance between x0 and x1 is smaller than the
** distance between y0 and y1. "The inclination is going up"
*/

void	draw_up(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	av;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, fdf->color);
	av = 2 * fdf->dx - fdf->dy;
	inc1 = 2 * (fdf->dx - fdf->dy);
	inc2 = 2 * fdf->dx;
	while (i < fdf->dy)
	{
		if (av >= 0)
		{
			fdf->x0 = fdf->x0 + fdf->incx;
			av = av + inc1;
		}
		else
			av = av + inc2;
		fdf->y0 = fdf->y0 + fdf->incy;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, fdf->color);
		i++;
	}
}

/*
** The gradient decreses, the distance between x0 and x1 is bigger than the
** distance between y0 and y1. "The inclination is going down"
*/

void	draw_down(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	av;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, fdf->color);
	av = 2 * fdf->dy - fdf->dx;
	inc1 = 2 * (fdf->dy - fdf->dx);
	inc2 = 2 * fdf->dy;
	while (i < fdf->dx)
	{
		if (av >= 0)
		{
			fdf->y0 = fdf->y0 + fdf->incy;
			av = av + inc1;
		}
		else
			av = av + inc2;
		fdf->x0 = fdf->x0 + fdf->incx;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, fdf->color);
		i++;
	}
}

/*
** Calculates the distances points move in the axis. Then the increments for the
** inclination of the lines. In the case when dy is bigger than dx, we would use
** draw_high, and draw_low for the opposite case.
*/

void	draw_line(t_fdf *fdf)
{
	fdf->dx = ft_abs(fdf->x1 - fdf->x0);
	fdf->dy = ft_abs(fdf->y1 - fdf->y0);
	fdf->incx = fdf->x0 < fdf->x1 ? 1 : -1;
	fdf->incy = fdf->y0 < fdf->y1 ? 1 : -1;
	if (fdf->dx < fdf->dy)
		draw_up(fdf);
	else
		draw_down(fdf);
}

/*
** Colors the background with the color defined in the fdf.h file.
*/

void	paint_background(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, j, i, BG_COLOR);
			j++;
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
			chose_color(fdf);
			if (fdf->index_x != fdf->length - 1)
				fdf->x1 = fdf->x0 + DISTANCE;
			draw_line(fdf);
			fdf->x0 = fdf->x1;
			fdf->index_x++;
		}
		fdf->index_y++;
		fdf->y0 = fdf->y0 + DISTANCE;
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
			chose_color(fdf);
			if (fdf->index_y != fdf->lines - 1)
				fdf->y1 = fdf->y0 + DISTANCE;
			draw_line(fdf);
			fdf->y0 = fdf->y1;
			fdf->index_y++;
		}
		fdf->index_x++;
		fdf->x0 = fdf->x0 + DISTANCE;
	}
}

/* void	chose_color(t_fdf *fdf)
{
	if (fdf->index_y != fdf->lines - 1)
	{
		if (fdf->map[fdf->index_y + 1][fdf->index_x] != 0 \
			&& fdf->map[fdf->index_y][fdf->index_x] != 0)
		{
			fdf->color = PEAK_COLOR;

		else
		{
			fdf->color = LINE_COLOR;
			return;
		}
	}
	if (fdf->index_x != fdf->length - 1)
	{
		if (fdf->map[fdf->index_y][fdf->index_x + 1] != 0 \
			&& fdf->map[fdf->index_y][fdf->index_x] != 0)
		{
			fdf->color = PEAK_COLOR;
			return;
		}
		else
		{
			fdf->color = LINE_COLOR;
			return;
		}
	}
}  */

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

void	redraw(t_fdf *fdf)
{
	paint_background(fdf);
	draw_hgrid(fdf);
	draw_vgrid(fdf);
}