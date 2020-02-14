# 7_FDF
Project fdf done at Hive Helsinki

# TODO:
        
        - Remove -g from Makefile
        - Remove <stdio.h> from fdf.h
		- Remove the long comp from Makefile

# 1 - Beginning. Initial testing and project setup.
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

In the end I wanted to install the library on my laptop. The steps I took were the following:

1. Download the library from 

	https://projects.intra.42.fr/uploads/document/document/1172/sources.tgz

2. Unpack the tgz file.

3. Download XQuartz and install it.

	https://kb.rice.edu/74034
	
4.
	cd minilibx
	make
	cd test
	./mlx-test

5. After the test is done and I check it is working, I move the compilation to the right folders.

	sudo cp mlx.h /usr/X11/include
	sudo cp libmlx.a /usr/X11/lib
	sudo cp libmlx_intel-mac.a /usr/X11/lib

6. Add this to the Makefile

	-I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext

Now my Makefile has this compilation line that worked on my laptop.

	$(NAME): lib
	@gcc -Wall -Wextra -Werror -g -o fdf main.c draw.c read.c -L ../libft -lft -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework Appkit -I ../includes -I ../libft/includes -I /usr/X11/include

To make a Makefile that works on laptop and on the school computer I made this:

	NAME = fdf
	CC = gcc
	CFLAG = -Wall -Wextra -Werror -g
	SRCDIR = 
	INCDIR = ../includes
	LIBDIR = ../libft
	LIBINC = $(LIBDIR)/includes
	LIBS = -lft -lmlx
	INCLUDES = -I $(INCDIR) -I $(LIBINC)
	FRAMEWORKS = -framework OpenGL -framework AppKit
	SRC = main.c \
		draw.c \
		read.c

	SOURCES = $(addprefix $(SRCDIR), $(SRC))
	OBJECTS = $(notdir $(SOURCES:.c=.o))

	all: lib $(NAME)

	lib:
		@make -C $(LIBDIR)
		@echo "Library compiling...	\033[1;32mdone\033[m"

	$(NAME): lib
		@gcc -Wall -Wextra -Werror -g -o fdf main.c draw.c read.c -L ../libft -lft -lmlx -framework OpenGL -framework AppKit -I ../includes -I ../libft/includes
		@rm -f $(OBJECTS)
		@echo "Binary  compiling...	\033[1;32mdone\033[m"

	clean:
		@rm -f $(OBJECTS)
		@echo "Objects  cleaning...	\033[1;32mdone\033[m"
		@make -C $(LIBDIR) clean
		@echo "Library  cleaning...	\033[1;32mdone\033[m"

	fclean: clean
		@rm -f $(NAME)
		@make -C $(LIBDIR) fclean
		@echo "Complete cleaning...	\033[1;32mdone\033[m"

	re: fclean all

	laptop: fclean lib
		@gcc -Wall -Wextra -Werror -g -o fdf main.c draw.c read.c -L ../libft -lft -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework Appkit -I ../includes -I ../libft/includes -I /usr/X11/include
		@rm -f $(OBJECTS)
		@echo "Binary  compiling...	\033[1;32mdone\033[m"

	.PHONY: all lib clean fclean re laptop



# 2 - Architecture plan

TODO:
        - Read file function
        - 2D array with the values read from the file. Or perhaps a structure with all the values.

This project needs to read from a file the points that will need to draw in space. These files are of the type:

        0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
        0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
        0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
        0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
        0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
        0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
        0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
        0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

The result should be something like this:

![666](https://github.com/kipVk/7_fdf/blob/master/resources/666.png)
![mars](https://github.com/kipVk/7_fdf/blob/master/resources/mars.png)
![42](https://github.com/kipVk/7_fdf/blob/master/resources/42.png)

Where the 2D array represents x and y coordinate, and the numeric value represents the z coordinate.
The points parsed on the file need to be vertex on the grid that will be drawn.

Naturally, the first step would be to read the file and add all those values to the coordinates. I'm thinking a 2D array might work.
Maybe a structure with all the values there will actually be more useful.

My main function should do the following:

        - Initialize the struct
        - Open the file
        - Read the file
        - Close the file
        - Initialize the mlx
        - Create new window
        - Get the key hooks
        - Mlx loop
        - If there's more than one file, show usage.

Read the file function needs to do the following:

        - Allocate memory for the height and width of the map.
        - Check for errors in the file.
        - Free in case of error.
        - Free the line read once the info is stored on the variables.
        - Get the values into the variables.
        - Split spaces to get the right values.
        - Get the numbers.

I have modified the Makefile so the .h are in the includes folder, and the .c are in the srcs folder.

Now it looks like this:

        NAME = fdf
        CC = gcc
        CFLAG = -Wall -Wextra -Werror -g
        SRCDIR = 
        INCDIR = ../includes
        LIBDIR = ../libft
        LIBINC = $(LIBDIR)/includes
        LIBFT = -lft
        LIBX = -lmlx
        SRC = main_win.c

        SOURCES = $(addprefix $(SRCDIR), $(SRC))
        OBJECTS = $(notdir $(SOURCES:.c=.o))

        all: lib $(NAME)

        lib:
                make -C $(LIBDIR)

        $(NAME): lib
                $(CC) $(CFLAG) -I $(INCDIR) -I $(LIBINC) -c $(SOURCES)
                $(CC) -o $(NAME) $(OBJECTS) -I $(INCDIR) -I $(LIBINC) -L $(LIBDIR) $(LIBFT) $(LIBX) -framework OpenGL -framework AppKit

        clean:
                rm -f $(OBJECTS)
                make -C $(LIBDIR) clean

        fclean: clean
                rm -f $(NAME)
                make -C $(LIBDIR) fclean

        re: fclean all

        .PHONY: all lib clean fclean re

It compiles the library from the libft folder, and then compiles the program with the system minilibX library.


# 3 - Tests

Managed to make some line drawings on the screen. Made the finnish flag, and the brittish flag, to see how I can pain with different colors and inclinations. I can also paint the background in any color I want.

![Suomen Lippu](https://github.com/kipVk/7_fdf/blob/master/resources/suomen_lippu.png)

# 4 - Implementation

By searching on the Spanish, English and French wikipedias for the Bresenham's algorithm, I managed to combine all the pseudocode into some functioning code in draw.c. First we have draw_line, a function that plots the line, calculates que inclinations and distances and based on that, determines if the line goes up or down.

	void	draw_line(t_fdf *fdf)
	{
		fdf->dx = ft_abs(fdf->x1 - fdf->x0);
		fdf->dy = ft_abs(fdf->y1 - fdf->y0);
		fdf->incx = fdf->x0 < fdf->x1 ? 1 : -1;
		fdf->incy = fdf->y0 < fdf->y1 ? 1 : -1;
		if (fdf->dx < fdf->dy)
			draw_up(fdf);
		else
			draw_down(fdf);
	}

Then calls the specific function for each case:

	void	draw_down(t_fdf *fdf)
	{
		int	inc1;
		int	inc2;
		int	av;
		int	i;

		i = 0;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, LINE_COLOR);
		av = 2 * fdf->dy - fdf->dx;
		inc1 = 2 * (fdf->dy - fdf->dx);
		inc2 = 2 * fdf->dy;
		while (i < fdf->dx)
		{
			if (av >= 0)
			{
				fdf->y0 = fdf->y0 + fdf->incy;
				av = av + inc1;
			}
			else
				av = av + inc2;
			fdf->x0 = fdf->x0 + fdf->incx;
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, LINE_COLOR);
			i++;
		}
	}

	void	draw_up(t_fdf *fdf)
	{
		int	inc1;
		int	inc2;
		int	av;
		int	i;

		i = 0;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, LINE_COLOR);
		av = 2 * fdf->dx - fdf->dy;
		inc1 = 2 * (fdf->dx - fdf->dy);
		inc2 = 2 * fdf->dx;
		while (i < fdf->dy)
		{
			if (av >= 0)
			{
				fdf->x0 = fdf->x0 + fdf->incx;
				av = av + inc1;
			}
			else
				av = av + inc2;
			fdf->y0 = fdf->y0 + fdf->incy;
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, LINE_COLOR);
			i++;
		}
	}

This achieves the desired results, using the struct t_fdf to store all the variables necessary.
  
I made the Makefile more interesting by silencing the outputs and printing a nice green message when things go well instead. The result is:

	NAME = fdf
	CC = gcc
	CFLAG = -Wall -Wextra -Werror -g
	SRCDIR = 
	INCDIR = ../includes
	LIBDIR = ../libft
	LIBINC = $(LIBDIR)/includes
	LIBS = -lft -lmlx
	INCLUDES = -I $(INCDIR) -I $(LIBINC)
	FRAMEWORKS = -framework OpenGL -framework AppKit
	SRC = main.c \
		draw.c

	SOURCES = $(addprefix $(SRCDIR), $(SRC))
	OBJECTS = $(notdir $(SOURCES:.c=.o))

	all: lib $(NAME)

	lib:
		@make -C $(LIBDIR)
		@echo "Library compiling...	\033[1;32mdone\033[m"

	$(NAME): lib
		@$(CC) $(CFLAG) $(INCLUDES) -c $(SOURCES)
		@$(CC) -o $(NAME) $(OBJECTS) -L $(LIBDIR) $(LIBS) $(FRAMEWORKS)
		@echo "Binary  compiling...	\033[1;32mdone\033[m"

	clean:
		@rm -f $(OBJECTS)
		@echo "Objects  cleaning...	\033[1;32mdone\033[m"
		@make -C $(LIBDIR) clean
		@echo "Library  cleaning...	\033[1;32mdone\033[m"

	fclean: clean
		@rm -f $(NAME)
		@make -C $(LIBDIR) fclean
		@echo "Complete cleaning...	\033[1;32mdone\033[m"

	re: fclean all

	.PHONY: all lib clean fclean re

Now that we can draw lines in all directions, it's time to start reading files.

I've added the function ft_file_line_count to the library:

	int		ft_file_line_count(int fd)
	{
		char 	*line;
		int		count;

		count = 0;
		while (get_next_line(fd, &line) == 1)
			count++;
		return (count);
	}

With this function we can know how big the array is going to be.

I made the function:

	void	get_map_value(t_fdf *fdf, int row, char *line)
	{
		int i;
		char **str;

		i = 0;
		str = ft_split_whitespaces(line);
		if (!(fdf->map[row] = (int *)malloc(sizeof(int) * ft_count_words(line))))
			ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
		while (str[i])
		{
			fdf->map[row][i] = ft_atoi(str[i]);
			i++;
		}
	}

That splits the line by the spaces, and saves on the 2D array fdf->map the values of it, already on int format.

I had a problem with my makefile to compile the debug file, so I used this command to compile. This generates the .dSYM file that is used by Visual Studio Code to debug:

	gcc -Wall -Wextra -Werror -g -o fdf main.c draw.c read.c -L ../libft -lft -lmlx -framework OpenGL -framework AppKit -I ../includes -I ../libft/includes

I made the function:

	void	draw_hgrid(t_fdf *fdf)
	{
		int i;
		int j;

		i = 0;
		fdf->y0 = INIT_Y;
		fdf->x0 = INIT_X;
		fdf->x = fdf->x0;
		while (i < fdf->lines)
		{
			j = 0;
			fdf->y1 = fdf->y0;
			fdf->x0 = fdf->x;
			while (j < fdf->length)
			{
				if (j != fdf->length - 1)
					fdf->x1 = fdf->x0 + DISTANCE;
				draw_line(fdf);
				fdf->x0 = fdf->x1;
				j++;
			}
			i++;
			fdf->y0 = fdf->y0 + DISTANCE;
		}
	}

That draws horizontal lines on the grid:

![Horizontal lines](https://github.com/kipVk/7_fdf/blob/master/resources/hor_lines.png)

And the function:

	void	draw_vgrid(t_fdf *fdf)
	{
		int i;
		int j;

		i = 0;
		fdf->y0 = INIT_Y;
		fdf->x0 = INIT_X;
		fdf->y = fdf->y0;
		while (i < fdf->length)
		{
			j = 0;
			fdf->x1 = fdf->x0;
			fdf->y0 = fdf->y;
			while (j < fdf->lines)
			{
				if (j != fdf->lines - 1)
					fdf->y1 = fdf->y0 + DISTANCE;
				draw_line(fdf);
				fdf->y0 = fdf->y1;
				j++;
			}
			i++;
			fdf->x0 = fdf->x0 + DISTANCE;
		}
	}

For the vertical lines so we have a grid:

![Grid](https://github.com/kipVk/7_fdf/blob/master/resources/grid.png)

Once we are able to paint lines in any direction with the bresenham ecuations, we need to calculate the orthogrphic projections of each of the vertex.
For that, I found this document quite useful:

	https://en.wikipedia.org/wiki/3D_projection

Basically, defining the vector (dx, dy, dz) as the position of the point respect to a coordinate system defined by the camera, where cx, cy, cz is the 3d position of a point C representing the camera (where the viewer is, so screen_w/2 screen_h/2 if we set it in the center of the screen), where sx, sy, sz are scales:

	dx = (cy * ((sz * y) + (cz * x))) - (sy * z)
	dy = (sx * ((cy * z) + (sy * ((sz * y) + (cz * x))))) + (cx * ((cz * y) - (sz * x)))
	dz = (cx * ((cy * z) + (sy * ((sz * y) + (cz * x))))) - (sx * ((cz * y) - (sz * x)))

If we consider rx, ry as the recording surface, sx and sy as the display size, and rz the distance from the recording surface to the camera, and dz is the distance from the 3d point to the camera, it can be expressed as:

	bx = (dx * sx) / (dz * rx) * rz
	by = (dy * sy) / (dz * ry) * rz

So, with these formulas in mind, let's see if i can actually transform these data into my own program's data.
 # Clone this repo to vogsphere

Go to the kip git hub folder
        
        git remote add origin2 vogsphere@vogsphere.hive.fi:intra/2020/activities/fdf/rcenamor
        git push -f origin2 master

With this, the vogsphere will have exactly the same branches, commits and pushes as the kvk repository
  
   
  
  
  
  
  
  
  
# References

https://github.com/qst0/ft_libgfx  
https://github.com/GlThibault/FdF  
https://github.com/jraleman/42_FDF  
https://github.com/Kikoman90/FdF  