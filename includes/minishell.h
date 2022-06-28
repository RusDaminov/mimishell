/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:23:28 by abernita          #+#    #+#             */
/*   Updated: 2022/05/19 15:23:31 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <signal.h>
//# include "builtins.h"
//# include "utils.h"
//# include "parser.h"
//# include "execute.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>


# define OPERATORS_NONE 0
# define OPERATORS_OR 1
# define OPERATORS_AND 2

typedef struct s_redirect
{
	bool		type;
	char		*path;
}	t_redirect;

typedef struct s_cmds
{
	char			**cmd;
	bool			read;
	bool			write;
	int				scope;
	int 			operators;
	int 			exit_status;
	t_redirect		**in_dir;
	t_redirect		**out_dir;
	struct s_cmds	*previous;
	struct s_cmds	*next;
	char 			*str;
}	t_cmds;

typedef struct s_variables
{
	char			**env;
	unsigned char	exit_status;
}	t_variables;

t_variables g_ourenv;

// builtins
typedef struct	s_builtins
{
	char	*name;
	int		(*func)(char *av);
}	t_builtins;

int	bt_cd(char **av);
int	bt_echo(char **av);
int bt_env(char **av);
int	bt_exit(char **av);
int	bt_export(char **av);
int	bt_pwd(char **av);
int	bt_unset(char *av);
int	bt_true(char **av);
int	bt_false(char **av);

// utils
int		ft_isspace(int c);

int		clear_list(t_cmds *node, int ret);
t_cmds	*find_listhead(t_cmds *node);
t_cmds	*find_last(t_cmds *node);
int		append_list(t_cmds **node);
t_cmds	*delete_node(t_cmds *node);

int		darr_size(char **str);
int		append_char(char **str, char c);
int		append_dstring(char ***org, char *str);
int		append_string(char **org, char *str);

char	*get_env_value(char *str);
int		free_env(void);
int		read_env(char **env);

// parser
# define REDIRECTIONS "<>"
# define ENDSTRING "\"\'$|"
# define ENDCOMMAND "&|("
# define HEREDOCEND " |&"

t_cmds	*parse(char *str, t_cmds *cur, char *av);

int		bracket_check(char **str, char **res, int scope);
char	*input_check(char *str, int scope);

int		check_quote(char **str, char **rem);
int		check_redirections(char **str, char **rem);
int		set_incorrect(char **str, char **rem);

int		redirect_size(t_redirect **red);
int		add_redirect(t_redirect ***cur);
int		parse_redirecions(char **str, char **strbuf, t_cmds **cur);

int 	parse_redirections_2(char **str, t_cmds **cur);

int		parse_quotes(char **str, char **strbuf);

int		parse_endcmds(char **str, char **strbuf, t_cmds **cur, char *av);

int		parse_or(char **str, char **strbuf, t_cmds **cur);

// execute
# define PIPE_ERR 2
# define MALLOC_ERR 3
# define FORK_ERR 4

typedef struct  s_execute
{
	t_list		*lst;
	int			s_fd;
	int 		fd[2];
	int 		exit;
	int 		s_in;
	int 		s_out;
}	t_execute;

typedef struct	s_pid
{
	int 		pid;
	int 		exit;
}	t_pid;

int				create_childs(t_cmds *data, t_execute *exec);
unsigned char	execute(t_cmds *data);

int				check_builtin(t_cmds *cmd, t_execute *exec);
void			collect_garbage(t_execute *exec);
int				execute_errors(int res, t_execute *exec);
int				execute_child_errors(int res, t_execute *exec, t_cmds *data);

void			check_operators(t_cmds **data, t_execute *exec);
int				has_heredoc(t_cmds *data);
void			my_wait(void *pid, int reset);
void			wait_for_real(t_list *lst, t_execute *exec);

int 			find_command(char *arg, char **str, char __attribute__((unused)) **env);

int				is_builtin(char *cmd);
int				exec_in_main(t_execute *exec, t_cmds *cmd);

int				redirect(t_cmds *data, t_execute *exec);

// signals
void			gsignal_ctlc(int sigtype);
void			fsignal_ctlc(int sigtype);
int				changetermios(bool toggle);
void			heredoc_ctlc(int sigtype);

#endif
