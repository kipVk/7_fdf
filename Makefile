# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/01/21 16:04:51 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAG = -Wall -Wextra -Werror -g
LIBDIR = libft
LIBINC = $(LIBDIR)/includes
INCDIR = .
SRCDIR =
LIB = -lft
SRC = board.c \
	  print2.c

SOURCES = $(addprefix $(SRCDIR), $(SRC))
OBJECTS = $(notdir $(SOURCES:.c=.o))

all: lib $(NAME)

lib:
	make -C $(LIBDIR)

$(NAME): lib
	$(CC) $(CFLAG) -I $(INCDIR) -I $(LIBINC) -c $(SOURCES)
	$(CC) -o $(NAME) $(OBJECTS) -I $(INCDIR) -I $(LIBINC) -L $(LIBDIR) $(LIB)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all lib clean fclean re
