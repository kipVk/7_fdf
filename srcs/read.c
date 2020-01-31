/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:35:06 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/31 15:04:46 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

/*
** Reads the file and gets all the points on the map.
*/

void	read_file(int fd, t_fdf *fdf)
{
	char *line;
	char **result;
	int i;

	if (!(fdf->map = (int **)malloc(sizeof(int *) * fdf->lines)))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		result = ft_split_whitespaces(line);
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
		fflush(stdout);
		free(line);
		free(result);
	}
}