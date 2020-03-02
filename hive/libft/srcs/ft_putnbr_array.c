/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:00:29 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs an array of numbers up to length len to the standard output,
** with the values separated by commas, and ending with a new linne
*/

#include "libft.h"

void	ft_putnbr_array(int *array, size_t len)
{
	size_t		i;

	ft_putnbr(array[0]);
	i = 1;
	while (i < len)
	{
		ft_putstr(", ");
		ft_putnbr(array[i]);
		i++;
	}
	ft_putchar('\n');
}
