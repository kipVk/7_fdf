/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsort_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:34:15 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Given an integer array arr of length len, sort the elements in increasing
** order, in situ (without allocating a new array), starting at index start.
*/

void	ft_arrsort_i(int *arr, unsigned int len, unsigned int start)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = start + 1;
	while (i < len)
	{
		j = start;
		while (j < i)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}
