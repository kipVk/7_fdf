/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_line_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:11:47 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 17:49:16 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counts how many lines a file has.
*/

#include "libft.h"

int		ft_file_line_count(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		count++;
	}
	return (count);
}
