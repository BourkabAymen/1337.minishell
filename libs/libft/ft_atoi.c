/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:05:43 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:05:46 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	tests that character is space symbol (\t \n \v \r \f and space)
**	
**	@param	ch		character
**	@return	int	zero if test false, else 1
*/
static int	is_space(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

/*
**	@brief	converts initial portion of string digits  to int representation
**	
**	@param	str		pointer to string with digits
**	@return	int		integer,  zero if integer not found or found zero!
*/
int	ft_atoi(const char *str)
{
	int	x;
	int	minus;

	x = 0;
	minus = -1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus = 1;
	while (*str && ft_isdigit(*str))
		x = x * 10 - (*str++ - '0');
	return (x * minus);
}
