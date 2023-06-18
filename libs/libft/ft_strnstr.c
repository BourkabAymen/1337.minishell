/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:07:48 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:07:50 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	locates the first occurrence string 'needle' in string 'haystack'.
**			searches in a substring 'haystack' of length at most 'len'
**	
**	@param	haystack	pointer to string
**	@param	needle		pointer to string
**	@param	len			lenght substring
**	@return	char*	pointer to the beginning of found string. NULL if not found
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	char	*start;

	len_needle = ft_strlen(needle);
	if (!len_needle)
		return ((char *)haystack);
	start = (char *)haystack;
	while (*start && start + len_needle <= haystack + len)
	{
		if (*start == *needle
			&& !ft_strncmp(start + 1, needle + 1, len_needle - 1))
			return (start);
		start++;
	}
	return (NULL);
}
