/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:58:11 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/06 15:32:12 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Iterates a list lst and applies the function f to each link to
**create a “fresh” list using malloc resulting from the successive
**applications of f. If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*nl_head;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new_list = ft_lstnew(NULL, 0)))
		return (NULL);
	new_list = f(lst);
	nl_head = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_list->next = f(lst);
		new_list = new_list->next;
	}
	return (nl_head);
}
