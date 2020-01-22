# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/01/22 20:54:02 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
