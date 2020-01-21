/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:06:33 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates a “fresh” string with room for a null terminator. Each character
** of the string is initialized at with character c.
**
** Returns the pointer to the fresh string. If the allocation fails,
** it returns NULL. NOTE: when size is 0, the result is system-dependent, as
** malloc(0) can return a valid or NULL pointer, depending on the
** implementation.
*/

#include "libft.h"

char	*ft_strnewc(size_t size, char c)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, c, size);
	str[size] = '\0';
	return (str);
}
