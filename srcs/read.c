/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:35:06 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/30 17:11:46 by rcenamor         ###   ########.fr       */
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

	if (!(fdf->map = (int **)malloc(sizeof(int *) * fdf->lines)))
		ft_puterr("ERROR: Memory Allocation error for fdf.map.", 1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s", line);
		fflush(stdout);
	}
}