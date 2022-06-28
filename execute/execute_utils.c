/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:21:28 by abernita          #+#    #+#             */
/*   Updated: 2022/06/20 21:22:31 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static const t_builtins	g_built_cmd[] = {
{"echo", &bt_echo},
{"cd", &bt_cd},
{"pwd", &bt_pwd},
{"export", &bt_export},
{"unset", &bt_unset},
{"env", &bt_env},
{"exit", &bt_exit},
{"false", &bt_false},
{"true", &bt_true},
{NULL, NULL}
};

int	check_builtin(t_cmds *cmd, t_execute *exec)
{
	int	i;

	i = 0;
	while (g_built_cmd[i].name)
	{
		if (!ft_strncmp(cmd->cmd[0], g_built_cmd[i].name,
				ft_strlen(g_built_cmd[i].name) + 1))
		{
			exec->exit = g_built_cmd[i].func(cmd->cmd);
			return (0);
		}
		i++;
	}
	return (1);
}

void	collect_garbage(t_execute *exec)
{
	if (exec->s_fd != -1)
	{
		close(exec->s_fd);
		exec->s_fd = -1;
	}
	if (exec->fd[0] != -1)
	{
		close(exec->fd[0]);
		exec->fd[0] = -1;
	}
	if (exec->fd[1] != -1)
	{
		close(exec->fd[1]);
		exec->fd[1] = -1;
	}
	ft_lstclear(&(exec->lst), free);
}

int	execute_errors(int res, t_execute *exec)
{
	perror("minishell");
	collect_garbage(exec);
	exec->exit = res;
	return (res);
}

int	execute_child_errors(int res, t_execute *exec, t_cmds *data)
{
	perror("minishell");
	collect_garbage(exec);
	clear_list(data, 0);
	data = 0;
	return (res);
}
