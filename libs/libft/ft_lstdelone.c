/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:06:42 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:06:45 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	deletes and free one element of the list
**	
**	@param	lst		pointer to element of the list
*/
void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst->val);
		free(lst);
	}
}
