/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:58:15 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 09:56:21 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Applies the function f to each character of the string passed as argument.
**Each character is passed by address to f to be
**modified if necessary
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s != NULL && f != NULL)
		while (*s)
		{
			f(s);
			s++;
		}
}
