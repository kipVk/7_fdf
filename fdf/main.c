/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:10:58 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:21:28 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

/*
** Print error if invalid input
*/

int		handle_error(void)
{
	ft_putstr("error\n");
	return (-1);
}

/*
** Print usage if number of parameters is not 1
*/

int		valid_arguments(int ac)
{
	if (ac == 2)
		return (1);
	ft_putstr("usage: ./fillit [tetriminos_file]\n");
	return (0);
}

/*
** Copy input from file, check some input errors: tetrimino not exactly
** 4 lines, empty lines between tetriminos not exactly 1, newline characters
** at end of file not exactly 1
*/

int		get_input(int fd, char **input)
{
	int		counter;
	char	*piece;

	counter = 0;
	piece = NULL;
	while (get_next_line(fd, &piece) > 0)
	{
		if (ft_strcmp(piece, "") == 0)
		{
			if (counter == 0)
				return (-1);
			ft_strcat(*input, "\n");
			counter == 4 ? counter = 0 : counter--;
		}
		else
		{
			if (counter > 4 || counter < -1 || ft_strlen(piece) > 4)
				return (-1);
			ft_strcat(*input, piece);
			counter++;
		}
		ft_strdel(&piece);
	}
	ft_strcat(*input, "\n");
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	char		*input;

	input = ft_strnew(1000);
	fd = 0;
	if (!valid_arguments(ac))
		return (handle_error());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (handle_error());
	if (get_input(fd, &input) == -1)
		return (handle_error());
	close(fd);
	fillit(input);
	while (3 < 2)
		ft_putstr(".");
	ft_strdel(&input);
	return (0);
}
