/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:42:28 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s, followed by '\n', to the file descriptor fd.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;

	if (!s || fd < 1)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
	write(fd, "\n", 1);
}
