/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:35:06 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/07 20:44:54 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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
	str = ft_split_whitespaces(line);
	if (!(fdf->map[row] = (int *)malloc(sizeof(int) * (len + 1))))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (str[i])
	{
		fdf->map[row][i] = ft_atoi(str[i]);
		i++;
	}
}

void	print_file(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->lines)
	{
		j = 0;
		while (j < fdf->length)
		{
			printf(" %d", fdf->map[i][j]);
			fflush(stdout);
			j++;
		}
		i++;
		printf("\n");
		fflush(stdout);
	}
}

void	read_file(int fd, t_fdf *fdf)
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
	/*print_file(fdf);*/
}
