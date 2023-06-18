/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:05:51 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:05:56 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	allocations memory like malloc, but uses count object multiply by 
**			size objects and then fills space zeros
**	
**	@param	count		count objects
**	@param	size		size one object in bytes
**	@return	void*	pointer to allocation memory or NULL if allocation fail
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = ft_malloc_x(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
