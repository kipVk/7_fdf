/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:34:52 by rcenamor          #+#    #+#             */
/*   Updated: 2020/02/28 18:16:58 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_wrdalloc(char **res, size_t len, int j)
{
	if (!(res[j] = (char *)malloc(sizeof(char) * len + 1)))
	{
		free(res);
		return (NULL);
	}
	else
		return (res[j]);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		t;
	char	**res;

	i = 0;
	j = -1;
	if ((res = (char **)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
	{
		while (++j < ft_count_words(s, c))
		{
			while (s[i] == c)
				i++;
			t = 0;
			res[j] = ft_wrdalloc(res, (ft_wrdlen(s, i, c) + 1), j);
			while (s[i] && s[i] != c)
				res[j][t++] = s[i++];
			res[j][t] = '\0';
			i++;
		}
		res[j] = NULL;
	}
	return (res);
}
