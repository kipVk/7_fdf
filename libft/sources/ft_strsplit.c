/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:34:52 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(char const *s, char c)
{
	size_t	i;
	size_t	n;
	int		was_prev_sep;

	i = 0;
	n = 0;
	was_prev_sep = 1;
	while (s[i])
	{
		if (s[i] == c)
			was_prev_sep = 1;
		else if (s[i] != c && was_prev_sep)
		{
			n++;
			was_prev_sep = 0;
		}
		i++;
	}
	return (n);
}

static char		*get_word(char const *s, char c, size_t *i)
{
	size_t	n;
	size_t	start;
	char	*word;

	n = 0;
	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i])
	{
		if (s[*i] == c)
			break ;
		n++;
		(*i)++;
	}
	word = ft_strsub(s, start, n);
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	char	**array;

	if (!s)
		return (NULL);
	words = get_words(s, c);
	i = 0;
	j = 0;
	array = (char **)ft_memalloc(words + 1);
	if (!array)
		return (NULL);
	while (j < words)
	{
		array[j] = get_word(s, c, &i);
		if (!array[j])
			ft_strdel_2d(array);
		j++;
	}
	array[j] = NULL;
	return (array);
}
