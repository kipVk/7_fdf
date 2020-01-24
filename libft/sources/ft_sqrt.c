/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:12 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/24 15:34:32 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		sq;
	int		count;

	count = 1;
	sq = 0;
	if (nb == 0)
		sq = 0;
	else if (nb == 1)
		sq = 1;
	else
	{
		while (++count < nb)
		{
			if ((count * count) == nb)
				sq = count;
		}
	}
	ft_putnbr(sq);
	return (sq);
}
