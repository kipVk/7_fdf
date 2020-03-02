/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:44:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates strdup (string.h).
**
** Allocates sufficient memory for a copy of the string s1, and does the copy.
**
** Returns the pointer to the copy. If the allocation failed, it returns NULL.
** NOTE: The original function sets errno to ENOMEM, but this version does not.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*s2;
	size_t	i;

	l = ft_strlen(s1);
	s2 = ft_strnew(l);
	i = 0;
	if (!s2)
		return (NULL);
	while (i < l)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
