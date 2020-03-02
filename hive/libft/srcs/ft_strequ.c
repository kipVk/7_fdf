/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:15:00 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compares (lexicographically) the null-terminated strings s1 and s2.
**
** Returns 1 if the strings are identical; otherwise, returns 0.
*/

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	else if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
