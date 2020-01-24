/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:04:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/24 16:54:16 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

int		key_press(int key, void *param)
{
	param = 0;
	if (key == 16)
		ft_putchar('Y');
	return (0);
}

int		mouse_press(int button, void *param)
{
	param = 0;
	if (button == 1)
		ft_putchar('1');
	return (0);
}

int		main(void)
{
	t_fdf	fdf;

	fdf.x0 = 100;
	fdf.y0 = 100;
	fdf.x1 = 100;
	fdf.y1 = 200;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIN_W, WIN_H, "FDF");
	paint_background(&fdf);
	draw_line(&fdf);
	//mlx_key_hook(fdf.win, key_press, fdf.mlx);
	mlx_hook(fdf.win, 2, 0, key_press, fdf.mlx);
	mlx_hook(fdf.win, 4, 0, mouse_press, fdf.mlx);
	mlx_loop(fdf.mlx);
}
