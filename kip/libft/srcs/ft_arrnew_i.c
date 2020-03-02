/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:39:04 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates memory for an integer array of length len, and initializes every
** element as the index.
**
** Returns the allocated array.
*/

#include "libft.h"

int		*ft_arrnew_i(size_t len)
{
	size_t	i;
	int		*arr;

	if (!(arr = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = i;
		i++;
	}
	return (arr);
}
