/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:07:35 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates a “fresh” memory area. The memory allocated is initialized to 0.
**
** Returns the pointer to the fresh memory area. If the allocation fails,
** it returns NULL. NOTE: when size is 0, the result is system-dependent, as
** malloc(0) can return a valid or NULL pointer, depending on the
** implementation.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(sizeof(void *) * size);
	if (!ptr)
		return (NULL);
	i = 0;
	ft_bzero(ptr, size);
	return (ptr);
}
