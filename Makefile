# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/03/02 17:59:08 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAG = -Wall -Wextra -Werror
SRCDIR = srcs/
INCDIR = includes
LIBDIR = libft
LIBINC = $(LIBDIR)/includes
LIBS = -lft -lmlx
INCLUDES = -I $(INCDIR) -I $(LIBINC)
FRAMEWORKS = -framework OpenGL -framework AppKit
SRC = main.c \
	draw.c \
	read.c \
	bre.c \
	keys.c \
	color.c \
	init.c

SOURCES = $(addprefix $(SRCDIR), $(SRC))
OBJECTS = $(notdir $(SOURCES:.c=.o))

all: lib $(NAME)

lib:
	@make -C $(LIBDIR)
	@echo "Library compiling...	\033[1;32mdone\033[m"

$(NAME): lib
	@gcc $(CFLAG) -o $(NAME) $(SOURCES) -L $(LIBDIR) $(LIBS) $(FRAMEWORKS) $(INCLUDES)
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
	@gcc $(CFLAG) -o $(NAME) $(SOURCES) -L $(LIBDIR) $(LIBS) -L /usr/X11/lib -lX11 -lXext $(FRAMEWORKS) $(INCLUDES) -I /usr/X11/include
	@rm -f $(OBJECTS)
	@echo "Binary  compiling...	\033[1;32mdone\033[m"

help:
	@echo "Usage: make {all|lib|clean|fclean|re|laptop|help}"

.PHONY: all lib clean fclean re laptop help
