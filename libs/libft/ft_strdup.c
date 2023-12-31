/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:08:04 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:08:06 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	allocates memory and copy string to this memory
**	
**	@param	s1		pointer to string
**	@return	char*	pointer to new string or NULL
*/
char	*ft_strdup(const char *s1)
{
	char	*new_str;
	int		len_s;
	int		i;

	len_s = ft_strlen(s1) + 1;
	new_str = (char *)ft_malloc_x(sizeof(*new_str) * len_s);
	if (!new_str)
		return (new_str);
	i = 0;
	while (i < len_s)
	{
		new_str[i] = s1[i];
		i++;
	}
	return (new_str);
}
