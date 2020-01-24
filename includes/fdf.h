/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/24 12:09:55 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# include <stdio.h>

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			incx;
	int			incy;
}				t_fdf;

#endif