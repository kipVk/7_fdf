/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:16:11 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates a “fresh” substring from the string given as argument.
** The substring begins at indexstart and is of size len. If start and len
** aren’t refering to a valid substring, the behavior is undefined.
**
** Returns the pointer to the fresh substring. If the allocation fails,
** the function returns NULL.
*/

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	fresh = ft_strnew(len);
	i = 0;
	if (!fresh)
		return (NULL);
	while (i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}
