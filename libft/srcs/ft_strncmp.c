/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:55:06 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates strncmp (string.h).
**
** Compares (lexicographically) up to n characters of the null-terminated
** strings s1 and s2.
**
** Returns 0 if the strings are identical; otherwise, returns a positive
** integer if the differing character is larger in s1, or a negative integer
** if the differing character is smaller in s1. The comparison is done using
** unsigned characters. NOTE: in the Hive machines, this returns 1, 0, or -1
** if using string literals, the difference between the characters otherwise.
** This implementation replicates the second behavior regardeless.
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			return (0);
		i++;
	}
	return (0);
}
