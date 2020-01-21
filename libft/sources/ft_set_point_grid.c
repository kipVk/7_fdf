/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_point_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:57:05 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets a point x and y values, from the position in and the width of the grid.
** Example: position 0 in a grid of width 2 is (0,0); position 2 is (0, 1);
*/

#include "libft.h"

void	ft_set_point_grid(t_point *point, size_t position, size_t width)
{
	point->x = position % width;
	point->y = position / width;
}
