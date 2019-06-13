/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:38:01 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 09:43:06 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates with malloc and returns a “fresh” memory area.
**The memory allocated is initialized to 0.
**If the allocation fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*pt;

	pt = malloc(size);
	if (pt == NULL)
		return (NULL);
	else
		ft_memset(pt, '\0', size);
	return (pt);
}
