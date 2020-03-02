/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:06:17 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replicates tolower (ctype.h).
**
** Converts an uppercase letter to the corresponding lowercase letter.
**
** Returns a lowercase letter.
*/

#include "libft.h"

int		ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	else
		return (c);
}
