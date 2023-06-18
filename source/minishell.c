/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:10:11 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:13:47 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

/*
**		@brief		Hello world!
*/
int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	char	*str;

	g_status = 0;
	rl_outstream = stderr;
	inicialise_struct(&msh, argc, argv, envp);
	ft_signal_main();
	while (true)
	{
		str = readline(MSH_AVE);
		if (g_status == 130)
		{
			msh.old_status = 1;
			g_status = 0;
		}
		if (!str)
			str = ft_strdup("exit");
		add_history(str);
		if (!parsing(&msh, str))
			run_commands_via_pipes(&msh);
		cleaning(&msh, str);
	}
}
