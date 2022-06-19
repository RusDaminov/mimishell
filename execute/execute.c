/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:23:28 by abernita          #+#    #+#             */
/*   Updated: 2022/06/19 21:23:31 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execute.h"

static void parent(t_execute *exec, t_cmds *data)
{
	if (exec->s_fd != -1)
		close(exec->sf);
	exec->s_fd = -1;
	if (exec->fd[1] != -1)
		close(exec->fd[1]);
	exec->fd[1] = -1;
	exec->s_fd = exec->fd[0];
	exec->fd[0] = -1;
	if (data->operators != OPERATORS_NONE)
	{
		wait_for_real(exec->lst, exec);
	}
}

int	create_childs(t_cmds *data, t_execute *exec)
{
	t_pid	*pid;
	t_list	*tmp;

	signal(SIGINT, SIG_IGN);
	pid = ft_calloc(sizeof(*pid), 1);
	if (!pid)
		return (execute_errors(MALLOC_ERR, exec));
	tmp = ft_lstnew(pid);
	if (!tmp)
		free(pid);
	if (!tmp)
		return (execute_errors(MALLOC_ERR, exec));
	ft_lstadd_back(&(exec->lst), tmp);
	if (data->write == 1 && pipe(exec->fd) == -1)
		return (execute_errors(PIPE_ERR, exec));
	pid->pid = fork();
	if (pid->pid == 0)
		exit(child(exec, data));
	parent(exec, data);
	return (0);
}

unsigned char	execute(t_cmds *data)
{
	t_execute	exec;

	exec = (t_execute){};
	exec.s_fd = -1;
	exec.fd[0] = -1;
	exec.fd[1] = -1;
	while (data != 0)
	{
		if (data->write == 0 && data->read ==0 && is_builtin(data->cmd[0]))
			exec.exit = exec_in_main(&exec, data);
		else if (create_childs(data, &exec))
			exec.exit = 1;
		if (has_heredoc(data))
		{
			wait_for_real(exec.lst, &exec);
			while (exec.exit == 1 && data && data->operators == 0)
				data = data->next;
		}
		if (data)
			data = data->next;
		check_operators(&data, &exec);
	}
	wait_for_real(exec.lst, &exec);
	collect_garbage(&exec);
	return (exec.exit);
}
