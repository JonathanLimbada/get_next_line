/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:15:10 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 10:55:13 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates with malloc and returns an array of “fresh
**strings all ending with ’\0’, including the array itself
**obtained by spliting s using the character c as a delimiter.
**If the allocation fails the function returns NULL
*/

static int	cwrds(char const *str, char delim, int index)
{
	int	count;

	if (!(str[index]))
		return (0);
	count = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != '\0' && str[index] != delim)
	{
		index++;
		count = 1;
	}
	return (count + cwrds(str, delim, index));
}

static int	str_len(char const *str, char delim, int index)
{
	int	len;

	len = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != delim && str[index] != '\0')
	{
		index++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	int		j;
	char	**array;
	int		k;

	if (!str || !c)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(*array) * (cwrds(str, c, 0) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < cwrds(str, c, 0))
	{
		k = 0;
		if (!(array[i] = ft_strnew(str_len(str, c, j))))
			return (NULL);
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j] != '\0')
			array[i][k++] = str[j++];
		array[i][k] = '\0';
		i++;
	}
	array[i] = 0;
	return (array);
}
