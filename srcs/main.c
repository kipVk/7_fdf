/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:04:10 by rcenamor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/20 16:36:21 by rcenamor         ###   ########.fr       */
=======
/*   Updated: 2020/02/25 14:50:36 by rcenamor         ###   ########.fr       */
>>>>>>> f24845694209c9efc7033e22c1c231080a115a7f
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	fdf->color = PEAK_COLOR;
	fdf->inc_z = 3;
	fdf->mul_x = 1;
}

int		key_press(int key, t_fdf *fdf)
{
	if (key == ESC_K)
		exit(0);
	if (key == UP_A || key == DOWN_A || key == RIGHT_A || key == LEFT_A)
		move(fdf, key);
	if (key == Q_K || key == A_K)
		rotate(fdf, key);
	if (key == W_K || key == S_K)
		change_height(fdf, key);
	if (key == SPC_K)
		space(fdf);
	if (key == ZOOM_I || key == ZOOM_O)
		zoom(fdf, key);
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

void	redraw(t_fdf *fdf)
{
	//mlx_clear_window(fdf->mlx, fdf->win);
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->image.data = mlx_get_data_addr(fdf->img, &fdf->image.bpp, \
		&fdf->image.size, &fdf->image.endian);
	if (fdf->persp % 2 == 0)
	{
		draw_v(fdf);
		draw_h(fdf);
	}
	else
	{
		draw_vgrid(fdf);
		draw_hgrid(fdf);
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
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
		if (file < 0)
			ft_puterr("ERROR: File not valid.", 1);
		fdf->lines = ft_file_line_count(file);
		close(file);
		file = open(av[1], O_RDONLY);
		ini_fdf(fdf);
		read_file(file, fdf);
		fdf->dist_x = (WIN_W / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
		fdf->dist_y = (WIN_H / ft_sqrt(pow((fdf->length * cos(M_PI / 3)), 2) + pow((fdf->lines * sin(M_PI / 6)), 2))) / 3;
		fdf->init_x = (WIN_W / 3);
		fdf->init_y = (WIN_H / 10);
		redraw(fdf);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_hook(fdf->win, 4, 0, mouse_press, fdf->mlx);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
