/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:51 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:52 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	lexicographically compare two strings. Not more n characters
**	
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@param	n		count bytes
**	@return	int	zero if strings are identical, 
**				else difference between two elements (unsinged char)
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i + 1 < n && s1[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*
**	@brief lexicographically compare two strings.
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@return	int	zero if strings are identical, 
**		else difference between two elements (unsinged char)
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
