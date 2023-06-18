/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:16 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:18 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	checks list is sort
**	
**	@param	lst		pointer to list's first element
**	@param	asc		ascending sort
**	@return	int		0 if list is sort, else diff betwen non sorted elements
*/
int	ft_lstsort(t_list *lst, bool asc)
{
	if (asc)
	{
		while (lst)
		{
			if (lst->next && lst->x > lst->next->x)
				return (lst->x - lst->next->x);
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			if (lst->next && lst->x < lst->next->x)
				return (lst->x - lst->next->x);
			lst = lst->next;
		}
	}
	return (0);
}
