/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:56:05 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/31 15:03:33 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_whitespaces(char *str)
{
	int			i;
	int			j;
	int			t;
	int			words;
	char		**res;

	i = 0;
	j = -1;
	words = ft_count_words(str);
	res = (char **)malloc(sizeof(char*) * (words + 1));
	while (++j < words)
	{
		t = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		res[j] = (char *)malloc(sizeof(char) * (ft_len_count(str, i) + 1));
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			res[j][t++] = str[i++];
		}
		res[j][t] = '\0';
		i++;
	}
	res[j] = NULL;
	return (res);
}