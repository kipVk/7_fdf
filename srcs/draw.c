/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:54:31 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/17 18:32:58 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	return (INIT_X - (fdf->scalx * y) + (fdf->scalx * x));
}

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	if (z > 30000)
		z = 30000;
	if (z < -30000)
		z = -30000;
	return (INIT_Y+ ((fdf->scaly) * x) + ((fdf->scaly) * y) - (z * 2));
}


void	fx(t_fdf *fdf)
{
	/* double cx = cos(0.3);
	double cy = cos(0.3);
	double cz = cos(0.3);
	double sx = sin(0.2);
	double sy = sin(0.2);
	double sz = sin(0.2);
	double dx = 0.0;
	double dy = 0.0;
	double dz = 0.0;
	int x = fdf->x0;
	int y = fdf->y0;
	int z = fdf->map[fdf->index_y][fdf->index_x];
	int rx = 100;
	int ry = 100;
	int rz = 5;
	
	dx = (cy * ((sz * y) + (cz * x))) - (sy * z);
	dy = (sx * ((cy * z) + (sy * ((sz * y) + (cz * x))))) + (cx * ((cz * y) - (sz * x)));
	dz = (cx * ((cy * z) + (sy * ((sz * y) + (cz * x))))) - (sx * ((cz * y) - (sz * x)));

	fdf->x0 = (dx * WIN_W) / (dz * rx) * rz;
	fdf->y0 = (dy * WIN_H) / (dz * ry) * rz;

	fdf->x0 = (rz * x) / (rz + z);
	fdf->y0 = (rz * y) / (rz + z);

	x = fdf->x1;
	y = fdf->y1;

	dx = 0.0;
	dy = 0.0;
	dz = 0.0;
	
	dx = (cy * ((sz * y) + (cz * x))) - (sy * z);
	dy = (sx * ((cy * z) + (sy * ((sz * y) + (cz * x))))) + (cx * ((cz * y) - (sz * x)));
	dz = (cx * ((cy * z) + (sy * ((sz * y) + (cz * x))))) - (sx * ((cz * y) - (sz * x)));

	fdf->x1 = (dx * WIN_W) / (dz * rx) * rz;
	fdf->y1 = (dy * WIN_H) / (dz * ry) * rz;

	fdf->x1 = (rz * x) / (rz + z);
	fdf->y1 = (rz * y) / (rz + z); */

	int x = fdf->x0;
	int y = fdf->y0;
	int z = fdf->map[fdf->index_y][fdf->index_x] + 1;

	fdf->x0 = x / z + 1;
	fdf->y0 = y / z + 1;

	x = fdf->x1;
	y = fdf->y1;

	fdf->x1 = x / z + 1;
	fdf->y1 = y / z + 1;
}

void	draw_hgrid(t_fdf *fdf)
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
			fdf->y0 = coord_y(fdf, j, i, fdf->map[i][j]);
			fdf->x1 = coord_x(fdf, j, i + 1);
			fdf->y1 = coord_y(fdf, j, i + 1, fdf->map[i + 1][j]);
			draw_line(fdf);
			j++;
		}
		i++;
	}
}

void	draw_vgrid(t_fdf *fdf)
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
			fdf->y0 = coord_y(fdf, j, i, fdf->map[i][j]);
			j++;
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->map[i][j]);
			draw_line(fdf);
		}
		i++;
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