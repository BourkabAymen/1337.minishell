/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:11:45 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:13:47 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value_from_envp(t_msh *msh, const char *key)
{
	t_list	*res;

	res = ft_lstfind(msh->lst_env, key);
	if (res)
		return (get_val_from_keyval(res->val));
	else
		return (ft_strdup(""));
}

void	remove_elem_from_envp(t_msh *msh, const char *key)
{
	t_list	*res;

	res = ft_lstpop_find(&msh->lst_env, key);
	if (res)
	{
		ft_split_free(msh->env);
		ft_lstdelone(res);
		msh->env = ft_lst_get_array(msh->lst_env);
	}
}

void	insert_or_update_elem_from_envp(t_msh *msh, const char *keyval)
{
	remove_elem_from_envp(msh, keyval);
	ft_lstadd_front(&msh->lst_env, ft_lstnew(ft_strdup(keyval)));
	ft_split_free(msh->env);
	msh->env = ft_lst_get_array(msh->lst_env);
}
