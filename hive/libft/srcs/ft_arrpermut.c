/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpermut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:10:20 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Given an integer array arr of length len, that can be permutated perms times,
** rearranges the array in the order corresponding to the lexicographical
** permutation number perms.
**
** Perms must be correct (hint: it's the factorial of len).
*/

#include "libft.h"

void	ft_arrpermut(int *arr, unsigned int len, unsigned long permuts,
		unsigned long permut)
{
	unsigned int	i;
	long			group;
	long			div;
	long			mod;

	i = 0;
	group = permuts;
	mod = permut;
	ft_arrsort(arr, len);
	while (i < len)
	{
		group = group / (len - i);
		div = mod / group;
		ft_swap(&arr[i], &arr[i + div]);
		i++;
		ft_arrsort_i(arr, len, i);
		mod = mod % group;
	}
}
