/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_in_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:06:14 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:06:15 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	checks if there is a character in the string
**	
**	@param	ch		character
**	@param	charset	pointer to set characters (string)
**	@return	int		0 if checks fail, else 1
*/
int	ft_ch_in_str(char ch, char *charset)
{
	while (*charset)
		if (*charset++ == ch)
			return (1);
	return (0);
}
