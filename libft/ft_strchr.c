/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:26:25 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 14:40:32 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ft_strchr locates the first occurrence of c in the string pointed to by s.
**The terminating null character is considered to be part of the string;
**therefore if c is `\0', the function locates the terminating `\0'.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	e;

	i = 0;
	e = (int)ft_strlen((char *)s);
	while (i <= e)
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		i++;
	}
	return (NULL);
}
