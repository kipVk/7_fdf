/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:53:21 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list resulting from the successive applications of f. If the
** allocation fails, the function returns NULL.
**
** Returns the pointer to the first element of the fresh list.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*elem;
	t_list		*first;
	t_list		*result;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	result = ft_lstnew(elem->content, elem->content_size);
	if (!result)
		return (NULL);
	first = result;
	lst = lst->next;
	while (lst)
	{
		elem = f(lst);
		result->next = ft_lstnew(elem->content, elem->content_size);
		if (!result->next)
			return (NULL);
		result = result->next;
		lst = lst->next;
	}
	return (first);
}
