/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:43:53 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates a copy of the string given as argument after trimming all
** occurences of character c at the beginning and the end.
**
** Returns the pointer to the new string. If s has no whitespaces at the
** beginning or at the end, the function returns a copy of s. If the
** allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	size_t	end;
	size_t	start;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	if (end == 0)
		return (ft_strnew(0));
	while (s[start] == c)
		start++;
	if (start == end)
		return (ft_strnew(0));
	end--;
	while (s[end] == c)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
