/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:04:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/14 14:18:45 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_fdf *fdf)
{
	if (key == ESC_K)
		exit(0);
	if (key == UP_A)
		fdf->count_up -= UP_VALUE;
	if (key == DOWN_A)
		fdf->count_up += UP_VALUE;
	if (key == RIGHT_A)
		fdf->count_side += SIDE_VALUE;
	if (key == LEFT_A)
		fdf->count_side -= SIDE_VALUE;
	if (key == ZOOM_I)
		fdf->distance += SIDE_VALUE;
	if (key == ZOOM_O)
		fdf->distance -= SIDE_VALUE;
	if (key == 49)
		fdf->angle_y *= (fdf->iso++ % 2) ? 0.2 : 0.3;
	//ft_putnbr(key);
	redraw(fdf);
	return (0);
}

int		mouse_press(int button, void *param)
{
	param = 0;
	if (button == 1)
		ft_putchar('1');
	return (0);
}

void	ini_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, WIN_NAME);
	fdf->x0 = 0;
	fdf->x1 = 0;
	fdf->y0 = 0;
	fdf->y1 = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->dx = 0;
	fdf->dy = 0;
	fdf->incx = 0;
	fdf->incy = 0;
	fdf->length = 0;
	fdf->count_up = 0;
	fdf->count_side = 0;
	fdf->distance = DISTANCE;
	//fdf->angle_y = cos(M_PI / 3);
	//fdf->angle_x = fdf->angle_y * sin(M_PI / 6);
	//fdf->x_value = 1.00;
	//fdf->zoom = ceil((fdf->length > fdf->lines)) \
	//	? (WIN_W / fdf->length) + 2 \
	//	: (WIN_H / fdf->lines) + 2;
	//fdf->iso = 1;
}

void	write_legend(t_fdf *fdf)
{
	mlx_string_put (fdf->mlx, fdf->win, 10, 10, PEAK_COLOR, " ^");
	mlx_string_put (fdf->mlx, fdf->win, 10, 15, PEAK_COLOR, "< > Move");
	mlx_string_put (fdf->mlx, fdf->win, 10, 20, PEAK_COLOR, " v");
	mlx_string_put (fdf->mlx, fdf->win, 10, 40, PEAK_COLOR, "ESC Close");
	mlx_string_put (fdf->mlx, fdf->win, 10, 60, PEAK_COLOR, "+ - Zoom");
}

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	//paint_background(fdf);
	//draw_thing(fdf);
	draw_hgrid(fdf);
	draw_vgrid(fdf);
	write_legend(fdf);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		file;

	if (ac != 2)
		ft_putendl("usage ./fd [map_file]");
	else
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			ft_puterr("ERROR: Memory Allocation error for fdf.", 1);
		file = open(av[1], O_RDONLY);
		if (file <0)
			ft_puterr("ERROR: File not valid.", 1);
		fdf->lines = ft_file_line_count(file);
		close(file);
		file = open(av[1], O_RDONLY);
		ini_fdf(fdf);
		read_file(file, fdf);
		redraw(fdf);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_hook(fdf->win, 4, 0, mouse_press, fdf->mlx);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
