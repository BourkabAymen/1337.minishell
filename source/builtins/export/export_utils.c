/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:09:35 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:13:47 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_write_error_export(char *exp)
{
	write(2, "export: '", 10);
	write(2, exp, ft_strlen(exp));
	write(2, "': not a valid identifier\n", 26);
	return (1);
}

static int	my_str_cmp(void *s1, void *s2)
{
	char	*one;
	char	*two;
	int		i;

	one = (char *)s1;
	two = (char *)s2;
	i = 0;
	while (one[i] == two[i] && two[i] && one[i])
		i++;
	if (one[i] == two[i])
		return (0);
	return (one[i] - two[i]);
}

void	sort_the_env(t_msh *msh, int len_env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < len_env)
	{
		j = 0;
		while (j < len_env - 1)
		{
			if (my_str_cmp(msh->env[j], msh->env[j + 1]) > 0)
			{
				tmp = msh->env[j];
				msh->env[j] = msh->env[j + 1];
				msh->env[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
