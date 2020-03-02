/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:10:31 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates strstr (string.h)
**
** Locates the first occurrence of the null-terminated string needle in the
** null-terminated string haystack.
**
** Returns the pointer to the first character of the needle in the haystack.
** If the needle is an empty string, returns the haystack. If the needle is
** not found, returns NULL.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] && (needle[j] == haystack[i + j]))
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
