/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:13:54 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 15:25:43 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Takes as a parameter the adress of a pointer to a link and
**frees the memory of this link and every successors of that link
**using the functions del and free. Finally the pointer to
**the link that was just freed must be set to NULL
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next;

	temp = *alst;
	if (del != NULL)
	{
		while (temp != NULL)
		{
			next = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = next;
		}
		*alst = NULL;
	}
}
