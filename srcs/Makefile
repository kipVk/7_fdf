# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/01/24 14:55:13 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAG = -Wall -Wextra -Werror -g
SRCDIR = 
INCDIR = ../includes
LIBDIR = ../libft
LIBINC = $(LIBDIR)/includes
LIBFT = -lft
LIBX = -lmlx
SRC = main.c \
	  draw.c

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
