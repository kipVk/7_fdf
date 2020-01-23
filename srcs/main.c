#include "mlx.h"
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

void paint_hor_line(void *mlx_ptr, void *win_ptr)
{
    int i;
    int j;

    i = 200;
    while (i < 300)
    {
        j = 0;
        while (j < 818)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x002f6c);
            j++;
        }
        i++;
    }
}

void paint_ver_line(void *mlx_ptr, void *win_ptr)
{
    int i;
    int j;

    i = 0;
    while (i < 500)
    {
        j = 200;
        while (j < 300)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x002f6c);
            j++;
        }
        i++;
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 818, 500, "FDF Suomen Lippu");
    paint_background(mlx_ptr, win_ptr);
    paint_hor_line(mlx_ptr, win_ptr);
    paint_ver_line(mlx_ptr, win_ptr);
    /* while (i < 500)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0xFFFFFF);
        mlx_pixel_put(mlx_ptr, win_ptr, i, 499 - i, 0x002f6c);
        //mlx_pixel_put(mlx_ptr, win_ptr, 251, 251, 0xFFFFFF);
        i++;
    } */
    //mlx_key_hook(win_ptr, key_press, mlx_ptr);
    mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);
    mlx_hook(win_ptr, 4, 0, mouse_press, mlx_ptr);
    mlx_loop(mlx_ptr);
}