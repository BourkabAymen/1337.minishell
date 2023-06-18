/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:00 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:01 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	iterates the list and applies the function to the content
**	
**	@param	lst		pointer to the list
**	@param	f		function to change content
*/
void	ft_lstiter(t_list *lst, void (*f)(char *))
{
	while (lst)
	{
		f(lst->val);
		lst = lst->next;
	}
}
