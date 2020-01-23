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

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_pixel_put(mlx_ptr, win_ptr, 251, 251, 0xFFFFFF);
    //mlx_key_hook(win_ptr, key_press, mlx_ptr);
    mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);
    mlx_hook(win_ptr, 4, 0, mouse_press, mlx_ptr);
    mlx_loop(mlx_ptr);
}