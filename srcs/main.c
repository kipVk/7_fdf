#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

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

void draw_line(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
 
    dx = ft_abs(x1-x0);
    dy = ft_abs(y1-y0); 
    err = (dx>dy ? dx : -dy)/2;
    sx = x0<x1 ? 1 : -1;
    sy = y0<y1 ? 1 : -1; 
    while(x0 != x1 && y0 != y1)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x000000);
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 818, 500, "FDF");
    paint_background(mlx_ptr, win_ptr);
    draw_line(20, 20, 520, 120, mlx_ptr, win_ptr);
    //mlx_key_hook(win_ptr, key_press, mlx_ptr);
    mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);
    mlx_hook(win_ptr, 4, 0, mouse_press, mlx_ptr);
    mlx_loop(mlx_ptr);
}