/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:08 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:10 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	create new list element
**	
**	@param	val		element content
**	@return	t_list*	pointer to new element or NULL
*/
t_list	*ft_lstnew(char *val)
{
	t_list	*elem;

	elem = ft_malloc_x(sizeof(*elem));
	if (elem)
	{
		elem->val = val;
		elem->next = NULL;
	}
	return (elem);
}
