/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:04:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/30 16:17:36 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

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

void		test_line(t_fdf *fdf)
{
	fdf->x0 = 100;
	fdf->y0 = 100;
	fdf->x1 = 100;
	fdf->y1 = 200;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FDF");
	paint_background(fdf);
	draw_line(fdf);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		file;

	if (ac != 2)
		ft_putendl("usage ./fd [file]");
	else
	{
		file = open(av[1], O_RDONLY);
		printf("%d", ft_file_line_count(file));
		fflush(stdout);
		test_line(&fdf);
		//mlx_key_hook(fdf.win, key_press, fdf.mlx);
		mlx_hook(fdf.win, 2, 0, key_press, fdf.mlx);
		mlx_hook(fdf.win, 4, 0, mouse_press, fdf.mlx);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
