/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:08:44 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:08:45 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	copies n bytes from src to dst. or less, if c occurs in src
**	
**	@param	dst		pointer to destination string
**	@param	src		pointer to source string
**	@param	c		character for stop copy
**	@param	n		max count bytes for copy
**	@return	void*	NULL if copied all n bytes, 
**					else pointer after character 'c' in the string dst
*/
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if ((unsigned char)c == ((unsigned char *)src)[i])
			return (dst + i + 1);
		i++;
	}	
	return (NULL);
}
