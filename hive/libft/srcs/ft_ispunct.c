/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:13:40 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates ispunct (ctype.h).
**
** Tests if a character is punctuation.
**
** Returns 1 if true and 0 if false.
*/

#include "libft.h"

int		ft_ispunct(int c)
{
	if (ft_isprint(c) && !ft_isspace(c) && !ft_isalnum(c))
		return (1);
	else
		return (0);
}
