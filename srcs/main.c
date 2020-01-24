/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rcenamor <rcenamor@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/24 15:41:18 by rcenamor		  #+#	#+#			 */
/*   Updated: 2020/01/24 15:43:49 by rcenamor		 ###   ########.fr	   */
/*																			*/
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

void	paint_background(void *mlx_ptr, void *win_ptr)
{
	int i;
	int j;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 818)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_fdf	fdf;

	fdf.x0 = 100;
	fdf.y0 = 100;
	fdf.x1 = 100;
	fdf.y1 = 200;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 818, 500, "FDF");
	paint_background(fdf.mlx, fdf.win);
	draw_line(&fdf);
	fdf.y0 = 200;
	fdf.x1 = 300;
	fdf.y1 = 200;
	draw_line(&fdf);
	fdf.x0 = 300;
	fdf.y0 = 200;
	fdf.x1 = 300;
	fdf.y1 = 100;
	draw_line(&fdf);
	fdf.x0 = 300;
	fdf.y0 = 100;
	fdf.x1 = 100;
	fdf.y1 = 100;
	draw_line(&fdf);
	fdf.x0 = 100;
	fdf.y0 = 100;
	fdf.x1 = 300;
	fdf.y1 = 200;
	draw_line(&fdf);
	fdf.x0 = 300;
	fdf.y0 = 100;
	fdf.x1 = 100;
	fdf.y1 = 200;
	draw_line(&fdf);
	fdf.x0 = 200;
	fdf.y0 = 100;
	fdf.x1 = 200;
	fdf.y1 = 200;
	draw_line(&fdf);
	fdf.x0 = 100;
	fdf.y0 = 150;
	fdf.x1 = 300;
	fdf.y1 = 150;
	draw_line(&fdf);
	//mlx_key_hook(fdf.win, key_press, fdf.mlx);
	mlx_hook(fdf.win, 2, 0, key_press, fdf.mlx);
	mlx_hook(fdf.win, 4, 0, mouse_press, fdf.mlx);
	mlx_loop(fdf.mlx);
}
