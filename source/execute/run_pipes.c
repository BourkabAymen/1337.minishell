/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:11:27 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:13:47 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**		@brief		runs command one by one
*/
void	run_commands_via_pipes(t_msh *msh)
{
	t_cmnd	*curr;

	ft_signal_run_pipes();
	curr = msh->lst_cmnd;
	while (curr && !g_status)
	{
		curr->arg = ft_lst_get_array(curr->lst_arg);
		if (curr->next)
		{
			if (pipe(curr->pipe_fd) < 0)
			{
				ft_raise_error(NULL, "msh");
				break ;
			}
			curr->out = curr->pipe_fd[1];
			curr->next->in = curr->pipe_fd[0];
			run_one_cmnd(msh, curr);
		}
		else
			run_one_cmnd_last(msh, curr);
		curr = curr->next;
	}
	wait_all_pipes(msh, curr);
	ft_signal_main();
}

/*
**		@brief		runs the command, no last in the pipes chain 	
*/
void	run_one_cmnd(t_msh *msh, t_cmnd *cmnd)
{
	cmnd->pid = fork();
	if (!cmnd->pid)
	{
		ft_signal_in_child();
		if (cmnd->next)
			close(cmnd->next->in);
		get_redirects(msh, cmnd, true);
		if (is_builtin(msh, cmnd->arg[0]))
		{
			run_builtin(msh, cmnd, cmnd->arg[0]);
			exit(g_status);
		}
		else
			run_command(msh, cmnd);
	}
	if (cmnd->in != STDIN)
		close(cmnd->in);
	if (cmnd->out != STDOUT)
		close(cmnd->out);
	if (cmnd->pid < 0)
	{
		ft_raise_error(0, "msh: fork:");
		g_status = 128;
	}
}

/*
**		@brief		runs the last (or only) command in the pipes chain 
*/
void	run_one_cmnd_last(t_msh *msh, t_cmnd *cmnd)
{
	if (is_builtin(msh, cmnd->arg[0]))
	{
		save_stnd_io(msh);
		if (!get_redirects(msh, cmnd, false))
			run_builtin(msh, cmnd, cmnd->arg[0]);
		restore_stnd_io(msh);
	}
	else
	{
		run_one_cmnd(msh, cmnd);
		if (!g_status)
		{
			waitpid(cmnd->pid, &msh->cur_status, 0);
			g_status = WEXITSTATUS(msh->cur_status);
			if (!g_status && WIFSIGNALED(msh->cur_status))
			{
				if (msh->cur_status == 2 || msh->cur_status == 3)
					ft_putendl_fd("", 2);
				g_status = 128 + WTERMSIG(msh->cur_status);
			}
		}
	}
}

/*
**		@brief		waiting for all forks to end their work
*/
void	wait_all_pipes(t_msh *msh, t_cmnd *last)
{
	t_cmnd	*cmnd;

	cmnd = msh->lst_cmnd;
	while (cmnd && cmnd->next && cmnd != last)
	{
		close(cmnd->pipe_fd[1]);
		close(cmnd->pipe_fd[0]);
		cmnd = cmnd->next;
	}
	cmnd = msh->lst_cmnd;
	while (cmnd && cmnd->next && cmnd != last)
	{
		if (cmnd->pid)
			waitpid(cmnd->pid, 0, 0);
		cmnd = cmnd->next;
	}
}
