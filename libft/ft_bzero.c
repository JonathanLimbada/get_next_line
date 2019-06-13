/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:25:11 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 15:08:54 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ft_bzero writes n zeroed bytes to the string s.
**If n is zero, ft_bzero does nothing
*/

void	ft_bzero(void *s, size_t n)
{
	char *p;

	p = s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}
