/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:06:18 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:06:19 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	@brief	counts chars from set in string
**	
**	@param	s		pointer to string
**	@param	ch		string of set chars
**	@return	int		number of chars
*/
int	ft_cnt_ch(const char *s, char *set)
{
	int	cnt;
	int	i;

	cnt = 0;
	while (*s)
	{
		i = 0;
		while (set[i])
		{
			if (*s == set[i++])
			{
				cnt++;
				break ;
			}
		}
		s++;
	}
	return (cnt);
}
