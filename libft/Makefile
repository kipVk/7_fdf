# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 16:14:36 by rcenamor          #+#    #+#              #
#    Updated: 2020/02/28 18:14:13 by rcenamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes/
SRCDIR = srcs/
SRC = ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_strnstr.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strdel.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_strsplit.c \
		  ft_itoa.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_putendl.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_isupper.c \
		  ft_islower.c \
		  ft_isspace.c \
		  ft_ispunct.c \
		  ft_isgraph.c \
		  ft_isxdigit.c \
		  ft_count_digits.c \
		  ft_abs.c \
		  ft_strdel_2d.c \
		  get_next_line.c \
		  ft_strtrimc.c \
		  ft_strnewc.c \
		  ft_putstr_2d.c \
		  ft_putnbr_array.c \
		  ft_set_point.c \
		  ft_set_point_grid.c \
		  ft_arrnew.c \
		  ft_arrdel.c \
		  ft_arrnew_i.c \
		  ft_arrpermut.c \
		  ft_arrsort.c \
		  ft_arrsort_i.c \
		  ft_swap.c \
		  ft_factorial.c \
		  ft_sqrt.c \
		  ft_file_line_count.c \
		  ft_puterr.c \
		  ft_count_words.c \
		  ft_len_count.c \
		  ft_split_whitespaces.c \
		  ft_wrdlen.c \
		  ft_count_space_words.c

SOURCES = $(addprefix $(SRCDIR), $(SRC))
OBJECTS = $(notdir $(SOURCES:.c=.o))

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJECTS)
	@rm -f $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
