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

void draw_line(t_fdf *fdf, void *mlx_ptr, void *win_ptr)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
 
    dx = ft_abs(fdf->x1 - fdf->x0);
    dy = ft_abs(fdf->y1 - fdf->y0); 
    err = (dx > dy ? dx : -dy) / 2;
    sx = fdf->x0 < fdf->x1 ? 1 : -1;
    sy = fdf->y0 < fdf->y1 ? 1 : -1; 
    while(fdf->x0 != fdf->x1 && fdf->y0 != fdf->y1)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, fdf->x0, fdf->y0, 0x000000);
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            fdf->x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            fdf->y0 += sy;
        }
    }
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_fdf   fdf;

    fdf.x0 = 20;
    fdf.x1 = 21;
    fdf.y0 = 21;
    fdf.y1 = 105;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 818, 500, "FDF");
    paint_background(mlx_ptr, win_ptr);
    draw_line(&fdf, mlx_ptr, win_ptr);
    //mlx_key_hook(win_ptr, key_press, mlx_ptr);
    mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);
    mlx_hook(win_ptr, 4, 0, mouse_press, mlx_ptr);
    mlx_loop(mlx_ptr);
}