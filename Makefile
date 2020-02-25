# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/02/25 20:17:40 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#@$(CC) $(CFLAG) $(INCLUDES) -c $(SOURCES)
#@$(CC) -o $(NAME) $(OBJECTS) -L $(LIBDIR) $(LIBS) $(FRAMEWORKS)

NAME = fdf
SYM = $(NAME).dSYM
CC = gcc
CFLAG = -Wall -Wextra -Werror -g
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
	  keys.c

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
	@rm -rf $(SYM)
	@make -C $(LIBDIR) fclean
	@echo "Complete cleaning...	\033[1;32mdone\033[m"

re: fclean all

laptop: fclean lib
	@gcc $(CFLAG) -o $(NAME) $(SOURCES) -L $(LIBDIR) $(LIBS) -L /usr/X11/lib -lX11 -lXext $(FRAMEWORKS) $(INCLUDES) -I /usr/X11/include
	@rm -f $(OBJECTS)
	@echo "Binary  compiling...	\033[1;32mdone\033[m"

.PHONY: all lib clean fclean re laptop
