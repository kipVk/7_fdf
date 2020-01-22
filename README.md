# 8_FDF
Project fdf done at Hive Helsinki

# Beginning
Started this project by trying to make the minilibx work by creating a simple window, and drawing 2 pixels.

For that I made this simple main.c file:

        #include "mlx.h"
        #include <unistd.h>

        void ft_putchar(char c)
        {
                write(1, &c, 1);
        }

        int key_press(int key, void *param)
        {
                ft_putchar('A');
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
                mlx_hook(win_ptr, 2, 2, key_press, mlx_ptr);
                mlx_loop(mlx_ptr);
        }

Compiling this with:

        cc main_win.c -L minilibx/ -lmlx -framework OpenGL -framework AppKit

It creates a window with 2 pixels in the middle, that prints A in the terminal whenever a key is pressed on the keyboard.

