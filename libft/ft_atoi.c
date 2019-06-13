/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:10:03 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/10 07:37:23 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ft_atoi converts the initial portion of the string pointed to
**by str to int representation.
*/

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	long	neg;

	i = 0;
	nbr = 0;
	neg = 1;
	while ((str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i]) && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + ((long)str[i] - '0');
		i++;
	}
	nbr *= neg;
	return (int)(nbr);
}
