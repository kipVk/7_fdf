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

        int mouse_press(int button, void *param)
        {
                ft_putchar('B');
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
                mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);
                mlx_hook(win_ptr, 4, 0, mouse_press, mlx_ptr);
                mlx_loop(mlx_ptr);
        }

Compiling this with:

        cc main_win.c -L minilibx/ -lmlx -framework OpenGL -framework AppKit

It creates a window with 2 pixels in the middle, that prints A in the terminal whenever a key is pressed on the keyboard, and B when a button is pressed on the mouse.

This was said by ohakola on Slack about setting up the project at home:

        This is how I got minilibx working home with a mac. Might help someone:
        Download minilibx from https://projects.intra.42.fr/uploads/document/document/1172/sources.tgz)
        
                cp -r ~/Downloads/minilibx /usr/local/lib/minilibx #or wherever
                cd /user/local/lib/minilibx && make
                cp *.a /user/local/lib/ #copy compiled files to lib
                brew cask install xquartz #may need eg. xcode-select --install after #install X11
                sudo ln -s /opt/X11/include/X11 /usr/local/include/X11
                #In your makefile add following flags to your compilation:
                -L /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

For now, I don't need to have the minilibx folder on the project, since it will be installed already on the school computers. I am deleting the folder from the repository.

Testing the key map and the mouse buttons, the main file that catches the events looks like this:

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

I have made a Makefile that compiles this with the installed library on the school Mac. The Makefile looks like this:
        
        NAME = fdf
        CC = gcc
        CFLAG = -Wall -Wextra -Werror -g
        SRCDIR =
        LIB = -lmlx
        SRC = main_win.c

        SOURCES = $(addprefix $(SRCDIR), $(SRC))
        OBJECTS = $(notdir $(SOURCES:.c=.o))

        all: $(NAME)

        $(NAME): 
                $(CC) $(CFLAG) -c $(SOURCES)
                $(CC) $(CFLAG) -o $(NAME) $(OBJECTS) $(LIB) -framework OpenGL -framework AppKit
                
        clean:
                rm -f $(OBJECTS)
                
        fclean: clean
                rm -f $(NAME)
                
        re: fclean all

        .PHONY: all clean fclean re

The -g flag is for debugging on VsCode.

At this stage, the project is up and running to start testing how to draw points.