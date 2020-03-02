/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_space_words.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:11:39 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 18:12:23 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_space_words(char *str)
{
	int i;
	int flag;
	int words;

	i = 0;
	flag = 1;
	words = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			flag = 1;
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && flag)
		{
			words++;
			flag = 0;
		}
		i++;
	}
	return (words);
}
