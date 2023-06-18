/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:08:30 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:08:32 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	fills a byte string with a byte value
**	
**	@param	b		pointer to string b
**	@param	c		filler
**	@param	len		count bytes to fill
**	@return	void*	original pointer to string b
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;
	unsigned int	fill;

	buf = (unsigned char *)b;
	fill = (unsigned char)c;
	i = 0;
	while (i < len)
		buf[i++] = fill;
	return (b);
}
