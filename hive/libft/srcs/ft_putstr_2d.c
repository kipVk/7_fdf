/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:19:14 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the null-terminated array s2d, composed of null-terminated strings,
** to the standard output.
*/

#include "libft.h"

void	ft_putstr_2d(char **s2d)
{
	int		i;

	i = 0;
	while (s2d[i])
	{
		ft_putendl(s2d[i]);
		i++;
	}
}
