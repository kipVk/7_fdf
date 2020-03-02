/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:53:40 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates strnstr (string.h)
**
** Locates the first occurrence of the null-terminated string needle in the
** null-terminated string haystack, within the first len characters of the
** haystack.
**
** Returns the pointer to the first character of the needle in the haystack.
** If the needle is an empty string, returns the haystack. If the needle is
** not found, returns NULL.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (needle[j] && (needle[j] == haystack[i + j]) && i + j < len)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
