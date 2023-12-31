/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:10:16 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/05/13 22:20:24 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

# define MSH_AVE	"\033[32mmsh$ \033[0m"
# define BUILTINS	"echo:cd:pwd:export:unset:env:exit"

# define OK			1
# define KO			0

# define L_ARR		1
# define R_ARR 		2
# define R_D_ARR	3
# define STDIN		0
# define STDOUT		1

# define ERR_PIPE	"msh: Syntax error near unexpected token '|'"
# define ERR_NEWL	"msh: Syntax error near newline"
# define ERR_TKN	"msh: syntax error near unexpected token: "

# define STND		"\033[0m"
# define GREEN		"\033[32m"
# define BLUE		"\033[36m"

# define DEBUG		1

extern int	g_status;

typedef struct s_cmnd
{
	struct s_cmnd	*next;
	char			**arg;
	t_list			*lst_arg;
	t_list			*redirects;
	int				pipe_fd[2];
	int				in;
	int				out;
	pid_t			pid;
	bool			is_fork;
}	t_cmnd;

typedef struct s_msh
{
	t_list	*lst_env;
	char	**env;
	char	**builtin;
	t_cmnd	*cmnd;
	t_cmnd	*lst_cmnd;
	int		old_in;
	int		old_out;
	int		old_status;
	int		cur_status;
}	t_msh;

// logic/

int		ft_echo(t_msh *msh, char **argv, char **env);
int		ft_exit(char **argv, t_msh *msh);
int		ft_env(char **argv, char **env, t_msh *msh);
int		ft_unset(char **argv, t_msh *msh);
int		ft_pwd(void);
int		ft_strcmp(const char *s1, const char *s2);
int		chdir_error(char *dir);
int		set_new_oldpwd(char *pwd_old, t_msh *msh);
int		ft_cd(char **argv, t_msh *msh);
int		set_new_pwd(t_msh *msh);

// logic/export

void	print_export(char **env);
int		ft_export(char **argv, t_msh *msh);
void	sort_the_env(t_msh *msh, int len_env);
int		ft_write_error_export(char *exp);

// signals / signal

void	ft_signal_main(void);
void	ft_signal_run_pipes(void);
void	ft_signal_in_child(void);
void	ft_signal_cltr_c(int sig);
void	ft_signal_pipes(int sig);

//  minishell
void	rl_replace_line(const char *text, int i);
int		main(int argc, char **argv, char **envp);

// inicialise

void	inicialise_struct(t_msh *msh, int argc, char **argv, char **envp);
void	update_shlvl(t_msh *msh);
void	cleaning(t_msh *msh, char *str);
void	ft_lstclear_cmnds(t_cmnd **cmnd);

// parsing / parsing

int		parsing(t_msh *msh, char *s);
void	parsing_check_pipes(char *s);
void	parsing_by_words(t_msh *msh, char *s);
void	parsing_word(t_msh *msh, char *s, size_t *i);

// parsing / ft_parsing_dollar

char	*ft_parsing_dollar(t_msh *msh, char *s, size_t *i);
void	ft_add_env_or_no(t_list	**chars, char *env_val);

// parsing / parsing_utils

t_cmnd	*new_command(void);
char	*get_quotes_string(t_msh *msh, char *s, size_t *i);
void	add_keyword(t_msh *msh, t_list **chars, bool is_redirect);
char	*get_key(bool digit, char *s, size_t *i);
int		skip_brackets(char *str);

// list_utils / envp

char	*get_value_from_envp(t_msh *msh, const char *key);
void	remove_elem_from_envp(t_msh *msh, const char *key);
void	insert_or_update_elem_from_envp(t_msh *msh, const char *keyval);

// list_utils / envp_util

size_t	ft_keylen(const char *keyval);
char	*get_val_from_keyval(const char *keyval);
char	*ft_chrdup(const char ch);
void	update_underscore(t_msh *msh, char *word);

// list_utils / ft_lstfunc

t_list	*ft_lstfind(t_list *lst, const char *key);
t_list	*ft_lstpop_find(t_list **lst, const char *key);
char	**ft_lst_get_array(t_list *lst);
char	*ft_lstdup_str(t_list *lst);
void	ft_cmnd_add_end(t_cmnd **lst, t_cmnd *new);

// execute / dups

void	save_stnd_io(t_msh *msh);
void	restore_stnd_io(t_msh *msh);
void	dups_input_output(t_cmnd *cmnd);

// execute / run_command

void	run_command(t_msh *msh, t_cmnd *cmnd);
void	run_builtin(t_msh *msh, t_cmnd *cmnd, char *name);
int		is_builtin(t_msh *msh, char *name);

// execute / run_pipes

void	run_commands_via_pipes(t_msh *msh);
void	run_one_cmnd(t_msh *msh, t_cmnd *cmnd);
void	run_one_cmnd_last(t_msh *msh, t_cmnd *cmnd);
void	wait_all_pipes(t_msh *msh, t_cmnd *last);

// execute / redirects

int		get_redirects(t_msh *msh, t_cmnd *cmnd, bool is_fork);
void	double_left_arrow(t_msh *msh, t_cmnd *cmnd, char *stop_word);
void	double_left_arrow_read(t_msh *msh, t_cmnd *cmnd, char *stop_word);
void	redirect_open_file(t_cmnd *cmnd, char *fname, int mode);

// execute / path_generator

char	**get_splited_path(t_msh *msh);
int		gen_next_path(char **argv, char **paths, char *name);
int		ft_is_path(char *s);

// raiser_error

void	ft_critical_error(char *msg, char *errno_msg, int err);
void	ft_raise_error(char *msg, char *errno_msg);
void	ft_raise_error_n(char *msg, int err_n);
int		print_errno(void);
char	*ft_replace_rdl(char *str);

// bonus / wildcard

void	wildcard(t_msh *msh, char *wilds);
void	get_and_check_files(t_msh *msh, DIR *dirp, char *wilds);
int		name_eq_wildcard(char *name, char *wilds);

#endif
