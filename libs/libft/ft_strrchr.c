/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:45 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:46 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	locates the last occurrence of c in the string s
**	
**	@param	s		pointer to string
**	@param	c		character to search
**	@return	char*	pointer to the found position c or NULL
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = NULL;
	while (*s)
	{
		if (*s == c)
			start = (char *)s;
		s++;
	}
	if (!c)
		start = (char *)s;
	return (start);
}
