/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:12 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/18 20:34:13 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt(double nb)
{
	double		sq;
	double		count;

	sq = nb / 2.2;
	count = 0.0;
	while(sq!= count)
	{
		count = sq;
		sq = (nb / count + count) / 2.0;
	}
	return (sq);
}
