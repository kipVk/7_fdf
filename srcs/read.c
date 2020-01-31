/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:35:06 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/31 15:53:18 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

/*
** Reads the file and gets all the points on the map.
*/

void		get_map_value(t_fdf *fdf, int row, char *line)
{
	int i;
	char **str;

	i = 0;
	str = ft_split_whitespaces(line);
	if (!(fdf->map[row] = (int *)malloc(sizeof(int) * ft_count_words(line))))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (str[i])
	{
		fdf->map[row][i] = ft_atoi(str[i]);
		i++;
	}
}

void	read_file(int fd, t_fdf *fdf)
{
	char *line;
	int i;
	int j;

	i = 0;
	if (!(fdf->map = (int **)malloc(sizeof(int *) * fdf->lines)))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		get_map_value(fdf, i, line);
		while (j < ft_count_words(line))
		{
			printf(" %d", fdf->map[i][j]);
			fflush(stdout);
			j++;
		}
		i++;
		printf("\n");
		fflush(stdout);
		free(line);
	}
}