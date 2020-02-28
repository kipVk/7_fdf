/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:38:18 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s, followed by '\n', to the standard output.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
	write(1, "\n", 1);
}
