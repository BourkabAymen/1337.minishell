/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:10:47 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:13:47 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **argv, t_msh *msh)
{
	t_list	*env;
	int		i;

	i = 1;
	env = msh->lst_env;
	if (argv[1] == NULL)
		return (OK);
	while (argv[i])
	{
		env = msh->lst_env;
		while (env && env->next)
		{
			if (argv[i][0] != '\0')
				remove_elem_from_envp(msh, argv[i]);
			env = env->next;
		}
		i++;
	}
	return (OK);
}
