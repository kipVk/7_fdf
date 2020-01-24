#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

int key_press(int key, void *param)
{
    param = 0;
    if (key == 16)
        ft_putchar('Y');
    return (0);
}

int mouse_press(int button, void *param)
{
    param = 0;
    if (button == 1)
        ft_putchar('1');
    return (0);
}

void paint_background(void *mlx_ptr, void *win_ptr)
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

void	draw_pos(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, 0x000000);
	e = (2 * fdf->dx) - fdf->dy;
	inc1 = 2 * (fdf->dx - fdf->dy);
	inc2 = 2 * fdf->dx;
	while (i < fdf->dy)
	{
		if (e >= 0)
		{
			fdf->x0 = fdf->x0 + fdf->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->y0 = fdf->y0 + fdf->incy;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, 0x000000);
		i++;
	}
}

void	draw_neg(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, 0x000000);
	e = (2 * fdf->dy) - fdf->dx;
	inc1 = 2 * (fdf->dy - fdf->dx);
	inc2 = 2 * fdf->dy;
	while (i < fdf->dx)
	{
		if (e >= 0)
		{
			fdf->y0 = fdf->y0 + fdf->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->x0 = fdf->x0 + fdf->incx;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, 0x000000);
		i++;
	}
}
  /*   while(fdf->x0 != fdf->x1 && fdf->y0 != fdf->y1)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, fdf->x0, fdf->y0, 0x000000);
        e2 = err;
        if (e2 > -fdf->dx)
        {
            err -= fdf->dy;
            fdf->x0 += fdf->incx;
        }
        if (e2 < fdf->dy)
        {
            err += fdf->dx;
            fdf->y0 += fdf->incy;
        }
    }
} */

void draw_line(t_fdf *fdf)
{
    //int err;
    //int e2;
 
    fdf->dx = ft_abs(fdf->x1 - fdf->x0);
    fdf->dy = ft_abs(fdf->y1 - fdf->y0); 
    //err = (fdf->dx > fdf->dy ? fdf->dx : -fdf->dy) / 2;
    fdf->incx = fdf->x0 < fdf->x1 ? 1 : -1;
    fdf->incy = fdf->y0 < fdf->y1 ? 1 : -1;
    if (fdf->dx < fdf->dy)
        draw_pos(fdf);
    else
        draw_neg(fdf);
}

int main()
{
    t_fdf   fdf;

    fdf.x0 = 100;
    fdf.y0 = 100;
    fdf.x1 = 100;
    fdf.y1 = 200;
    fdf.mlx = mlx_init();
    fdf.win = mlx_new_window(fdf.mlx, 818, 500, "FDF");
    paint_background(fdf.mlx, fdf.win);
    draw_line(&fdf);
    fdf.x0 = 100;
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
    //mlx_key_hook(fdf.win, key_press, fdf.mlx);
    mlx_hook(fdf.win, 2, 0, key_press, fdf.mlx);
    mlx_hook(fdf.win, 4, 0, mouse_press, fdf.mlx);
    mlx_loop(fdf.mlx);
}