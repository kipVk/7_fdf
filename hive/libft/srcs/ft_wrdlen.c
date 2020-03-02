/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:37:39 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 18:10:05 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wrdlen(const char *s, int i, char c)
{
	int size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}
