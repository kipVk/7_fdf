/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:34:15 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates a copy of the string given as argument without whitespaces
** at the beginning or at the end of the string. In this context, whitespaces
** refers to the following characters: ’ ’, ’\n’ and ’\t’.
**
** Returns the pointer to the new string. If s has no whitespaces at the
** beginning or at the end, the function returns a copy of s. If the
** allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	if (end == 0)
		return (ft_strnew(0));
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start == end)
		return (ft_strnew(0));
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
