/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:05 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:06 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	create new list, where each content is result successive applied
**			of the function to content element of old list
**	
**	@param	lst		pointer to the old list
**	@param	f		function for create new content
**	@return	t_list*	pointer to new list or NULL
*/
t_list	*ft_lstmap(t_list *lst, char *(*f)(char *))
{
	t_list	*begin;
	t_list	*cur;
	t_list	*new;

	begin = NULL;
	while (lst)
	{
		new = ft_lstnew(f(ft_strdup(lst->val)));
		if (!new)
		{
			ft_lstclear(&begin);
			return (NULL);
		}
		if (begin)
			ft_lstadd_back(&cur, new);
		else
		{
			begin = new;
			cur = new;
		}
		lst = lst->next;
	}
	return (begin);
}
