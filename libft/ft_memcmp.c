/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:56:31 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 13:20:07 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ft_memcmp function compares byte string s1 against byte string s2.
**Both strings are assumed to be n bytes long
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		if (ps1[i] == ps2[i])
			i++;
		n--;
	}
	return (0);
}
