/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:01:25 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/30 17:03:05 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prints an error message on the terminal and exits the program with an error
** code.
*/

#include "libft.h"

void	ft_puterr(char *msg, int err)
{
	ft_putendl(msg);
	exit(err);
}