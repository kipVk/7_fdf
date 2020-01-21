/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:37:00 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates memmove (string.h)
**
** Copies len bytes from string src to string dst. The two strings may overlap;
** the copy is always done in a nondestructive manner.
**
** Returns the pointer to dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if ((!dst && !src) || dst == src)
		return (dst);
	if (dst < src)
	{
		d = (char *)dst;
		s = (const char *)src;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (char *)dst + len - 1;
		s = (const char *)src + len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
