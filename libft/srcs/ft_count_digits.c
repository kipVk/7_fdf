/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:39:13 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counts the digits of an integer.
**
** Returns the number of digits.
*/

int		ft_count_digits(int n)
{
	int		len;
	long	nb;

	nb = (long)n;
	len = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
