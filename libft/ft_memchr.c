/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:23:13 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 12:45:36 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memchr function locates the first occurrence of c in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ps;

	ps = (const char *)s;
	i = 0;
	while (n--)
	{
		if (ps[i] == (char)c)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
