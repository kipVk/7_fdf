/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:35:25 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert an integer into a null-terminated string representing said integer.
**
** Returns the pointer to the string. If the allocation fails, the function
** returns NULL.
*/

#include "libft.h"

char			*ft_itoa(int n)
{
	long	nb;
	char	*s;
	int		i;

	i = ft_count_digits(n);
	nb = (long)n;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	s = ft_strnew(i);
	if (!s)
		return (NULL);
	i--;
	while (nb > 9)
	{
		s[i] = '0' + nb % 10;
		nb = nb / 10;
		i--;
	}
	s[i] = '0' + nb % 10;
	if (n < 0)
		s[0] = '-';
	return (s);
}
