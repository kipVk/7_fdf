/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/23 14:25:22 by rcenamor         ###   ########.fr       */
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
}				t_fdf;

#endif
