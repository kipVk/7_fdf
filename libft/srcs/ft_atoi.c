/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:56:01 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates atoi (stdlib.h).
**
** Converts ASCII string to integer.
**
** Returns the integer. NOTE: in the Hive machines, it returns -1 if above
** max long, and 0 if below min long. I replicated this behavior, but this is
** implementation specific.
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	n;
	int				sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		if ((sign == 1 && n > LONGMAX))
			return (-1);
		if ((sign == -1 && n > LONGMAX))
			return (0);
		i++;
	}
	return (sign * (int)n);
}
