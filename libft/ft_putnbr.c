/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:25:05 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 12:00:47 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Outputs the integer n to the standard output.
*/

void	ft_putnbr(int n)
{
	long	e;

	e = (long)n;
	if (n < 0)
	{
		ft_putchar('-');
		e = e * -1;
	}
	if (e >= 10)
	{
		ft_putnbr(e / 10);
		ft_putchar(e % 10 + '0');
	}
	else
		ft_putchar(e + '0');
}
