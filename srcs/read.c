/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:35:06 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 17:47:28 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Reads the file and gets all the points on the map. Checks also that all the
** lines in the map have the same amount of coordinates.
*/

void	get_map_value(t_fdf *fdf, int row, char *line)
{
	int		i;
	char	**str;
	int		len;

	i = 0;
	len = ft_count_words(line);
	if (fdf->length == 0)
		fdf->length = len;
	if (len != fdf->length)
		ft_puterr("ERROR: The map doesn't have consistent size.", 1);
	str = ft_strsplit(line, ' ');
	if (!(fdf->map[row] = (int *)malloc(sizeof(int) * (len + 1))))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (str[i])
	{
		fdf->map[row][i] = ft_atoi(str[i]);
		if (fdf->map[row][i] > 0 && fdf->map[row][i] > fdf->p_max_z)
			fdf->p_max_z = fdf->map[row][i];
		if (fdf->map[row][i] < 0 && fdf->map[row][i] < fdf->n_max_z)
			fdf->n_max_z = fdf->map[row][i];
		i++;
	}
	free(str);
}

/*
** Reads the file and calls the function that reads the values.
*/

void	read_map(t_fdf *fdf, int fd)
{
	char	*line;
	int		i;

	i = 0;
	if (!(fdf->map = (int **)malloc(sizeof(int *) * fdf->lines)))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (get_next_line(fd, &line) == 1)
	{
		get_map_value(fdf, i, line);
		free(line);
		i++;
	}
	fdf->n_max_z = (fdf->n_max_z == 0) ? -fdf->p_max_z : fdf->n_max_z;
}

/*
** Reads the file gets the number of lines.
*/

void	read_file(t_fdf *fdf, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_puterr("ERROR: File not valid.", 1);
	fdf->lines = ft_file_line_count(fd);
	/*close(fd);
	fd = open(file, O_RDONLY);
	read_map(fdf, fd);
	close(fd);*/
}
