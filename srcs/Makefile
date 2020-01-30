# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:54:03 by rcenamor          #+#    #+#              #
#    Updated: 2020/01/30 17:10:14 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
