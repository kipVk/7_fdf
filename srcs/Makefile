# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/02/14 13:17:18 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#@$(CC) $(CFLAG) $(INCLUDES) -c $(SOURCES)
#@$(CC) -o $(NAME) $(OBJECTS) -L $(LIBDIR) $(LIBS) $(FRAMEWORKS)

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
