/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:32:41 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates abs (stdlib.c).
**
** Computes the absolute value of the integer i.
**
** Returns i if i is positive, zero, or the minimum integer. Returns -i
** otherwise.
*/

#include "libft.h"

int		ft_abs(int i)
{
	if (i >= 0 || i == INTMIN)
		return (i);
	else
		return (-i);
}
