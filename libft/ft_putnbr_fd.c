/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:13:53 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 12:08:00 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Outputs the integer n to the file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	e;

	e = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		e = e * -1;
	}
	if (e >= 10)
	{
		ft_putnbr_fd(e / 10, fd);
		ft_putchar_fd(e % 10 + '0', fd);
	}
	else
		ft_putchar_fd(e + '0', fd);
}
