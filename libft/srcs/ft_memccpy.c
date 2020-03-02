/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:36:16 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates memccpy (string.h).
**
** Copies bytes from string src to string dst. If the character c (as
** converted to an unsigned char) occurs in the string src, the copy stops.
** Otherwise, n bytes are copied. The source and destination strings
** should not overlap, as the behavior is undefined.
**
** Returns the pointer to the byte after the copy of c in the string dst
** (if the character was found); otherwise, returns NULL.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n)
	{
		*d = *s;
		if (*d == (unsigned char)c)
		{
			d++;
			return ((void *)d);
		}
		d++;
		s++;
		n--;
	}
	return (NULL);
}
