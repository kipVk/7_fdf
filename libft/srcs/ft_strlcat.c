/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:49:04 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates strlcat (string.h)
**
** Appends string src to the end of dst.  It will append at most
** dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize
** (in practice this should not happen as it means that either dstsize is
** incorrect or that dst is not a proper string).
**
** Returns the total length of the string it tried to create.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	len;

	dlen = ft_strlen(dst);
	if (dlen > dstsize)
		dlen = dstsize;
	slen = ft_strlen(src);
	len = dlen + slen;
	if (dlen == dstsize)
		return (len);
	if (slen < dstsize - dlen)
	{
		ft_memcpy(dst + dlen, src, slen + 1);
		return (len);
	}
	ft_memcpy(dst + dlen, src, dstsize - dlen - 1);
	dst[dstsize - 1] = '\0';
	return (len);
}
