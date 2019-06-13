/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:19:28 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 13:33:02 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ft_strdup allocates sufficient memory for a copy of the string s1,
**does the copy, and returns a pointer to it. ft_strndu copies at most n
**characters from the string s1 always NUL terminating the copied string.
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*prt;

	i = 0;
	while (s1[i])
		i++;
	prt = (char *)malloc(i + 1 * sizeof(char));
	if (prt == '\0')
		return (NULL);
	i = 0;
	while (s1[i])
	{
		prt[i] = s1[i];
		i++;
	}
	prt[i] = 0;
	return (prt);
}
