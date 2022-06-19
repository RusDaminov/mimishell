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
