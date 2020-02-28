/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:06:07 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Calculates the factorial of a number.
**
** Returns the factorial. If the number is more than 20, it returns 20!.
*/

unsigned long	ft_factorial(unsigned long nbr)
{
	if (nbr == 0 || nbr == 1)
		return (nbr);
	else if (nbr > 20)
		return (ft_factorial(20));
	else
		return (nbr * ft_factorial(nbr - 1));
}
