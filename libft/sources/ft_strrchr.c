/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:51:19 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates strrchr (string.h)
**
** Locates the last occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is '\0', the functions locate
** the terminating '\0'.
**
** Returns the pointer to the character (if located); otherwise, returns NULL.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *found;

	found = NULL;
	if (c == '\0')
	{
		found = ft_strchr(s, '\0');
		return (found);
	}
	while (*s)
	{
		if (*s == c)
			found = (char *)s;
		s++;
	}
	return (found);
}
