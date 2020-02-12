/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:54:31 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/12 21:46:12 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	put_pixel(t_fdf *fdf, int y, int z, double uvector)
{
	//(void)uvector;
	//mlx_pixel_put(fdf->mlx, fdf->win, y, z, PEAK_COLOR);
	int		pos;

	if ((y > 0 && z > 0) && (y < WIN_W && z < WIN_H))
	{
		pos = (y * 4) + (z * WIN_W * 4);
		fdf->image.data[pos + fdf->count_side] = 0x4F + uvector;
		fdf->image.data[pos + fdf->count_side + 1] = 0x4F + uvector;
		fdf->image.data[pos + fdf->count_side + 2] = 0x4F + uvector;
		fdf->image.data[pos + fdf->count_side + 3] = 0x7F + uvector;
	}
}


/*
** The gradient increases, the distance between x0 and x1 is smaller than the
** distance between y0 and y1. "The inclination is going up"


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
}*/

/*
** The gradient decreses, the distance between x0 and x1 is bigger than the
** distance between y0 and y1. "The inclination is going down"
*

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
}*/

/*
** Calculates the distances points move in the axis. Then the increments for the
** inclination of the lines. In the case when dy is bigger than dx, we would use
** draw_high, and draw_low for the opposite case.
*/

/* void	draw_line(t_fdf *fdf)
{
	fdf->dx = ft_abs(fdf->x1 - fdf->x0);
	fdf->dy = ft_abs(fdf->y1 - fdf->y0);
	fdf->incx = fdf->x0 < fdf->x1 ? 1 : -1;
	fdf->incy = fdf->y0 < fdf->y1 ? 1 : -1;
	if (fdf->dx < fdf->dy)
		draw_up(fdf);
	else
		draw_down(fdf);
} */

void	draw_line(t_fdf *fdf)
{
	double y;
	double z;
	double delta_y;
	double delta_z;
	double uvector;

	y = fdf->x0;
	z = fdf->y0;
	delta_y = fdf->x1 - fdf->x0;
	delta_z = fdf->y1 - fdf->y0;
	uvector = sqrt((pow(delta_y, 2)) + (pow(delta_z, 2)));
	delta_y /= uvector;
	delta_z /= uvector;
	while (uvector > 0)
	{
		put_pixel(fdf, y, z, uvector);
		y += delta_y;
		z += delta_z;
		uvector -= 1;
	}
}

/*
** Colors the background with the color defined in the fdf.h file.
*

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
}*/

void	draw_hgrid(t_fdf *fdf, int y, int z)
{
	int		yt;
	int		zt;

	yt = y - fdf->length / 2;
	zt = z - fdf->lines / 2;
	fdf->x0 = fdf->angle_x * (yt - zt) * fdf->zoom;
	fdf->y0 = fdf->angle_y * (yt + zt) * fdf->zoom;
	fdf->y0 -= fdf->map[z][y] * fdf->x_value;
	fdf->x1 = fdf->angle_x * ((yt + 1) - zt) * fdf->zoom;
	fdf->y1 = fdf->angle_y * ((yt + 1) + zt) * fdf->zoom;
	fdf->y1 -= fdf->map[z][y + 1] * fdf->x_value;
	fdf->x0 += (WIN_W / 2) + fdf->x;
	fdf->x1 += (WIN_W / 2) + fdf->x;
	fdf->y0 += (WIN_H / 2) + fdf->y;
	fdf->y1 += (WIN_H / 2) + fdf->y;
	draw_line(fdf);
}

void	draw_vgrid(t_fdf *fdf, int y, int z)
{
	int		yt;
	int		zt;

	yt = y - fdf->length / 2;
	zt = z - fdf->lines / 2;
	fdf->x0 = fdf->angle_x * (yt - zt) * fdf->zoom;
	fdf->y0 = fdf->angle_y * (yt + zt) * fdf->zoom;
	fdf->y0 -= fdf->map[z][y] * fdf->x_value;
	fdf->x1 = fdf->angle_x * (yt - (zt + 1)) * fdf->zoom;
	fdf->y1 = fdf->angle_y * (yt + (zt + 1)) * fdf->zoom;
	fdf->y1 -= fdf->map[z + 1][y] * fdf->x_value;
	fdf->x0 += (WIN_W / 2) + fdf->x;
	fdf->x1 += (WIN_W / 2) + fdf->x;
	fdf->y0 += (WIN_H / 2) + fdf->y;
	fdf->y1 += (WIN_H / 2) + fdf->y;
	draw_line(fdf);
}

/*void	chose_color(t_fdf *fdf)
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
}*/

void	draw_thing(t_fdf *fdf)
{
	int		y;
	int		z;

	z = 0;
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->image.data = mlx_get_data_addr(fdf->img, &fdf->image.bpp, \
		&fdf->image.size, &fdf->image.endian);
	while (fdf->lines > z)
	{
		y = 0;
		while (fdf->length > y)
		{
			fdf->x0 = y;
			fdf->y0 = z;
			if (fdf->length > y + 1)
				draw_hgrid(fdf, y, z);
			if (fdf->lines > z + 1)
				draw_vgrid(fdf, y, z);
			y += 1;
		}
		z += 1;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
}
