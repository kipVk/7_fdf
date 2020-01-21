/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:58:11 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates isgraph (ctype.h).
**
** Tests if a character is printable (excluding space).
**
** Returns 1 if true and 0 if false.
*/

#include "libft.h"

int		ft_isgraph(int c)
{
	if (ft_isprint(c) && !ft_isspace(c))
		return (1);
	else
		return (0);
}
