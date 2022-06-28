/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:21:28 by abernita          #+#    #+#             */
/*   Updated: 2022/06/20 22:22:31 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_operators(t_cmds **data, t_execute *exec)
{
	if ((*data) && (*data)->previous->operators == OPERATORS_AND
		&& exec->exit != 0)
	{
		while ((*data) && ((*data)->previous->operators == OPERATORS_OR))
			(*data) = (*data)->next;
	}
	if ((*data) && (*data)->previous->operators == OPERATORS_OR
		&& exec->exit == 0)
	{
		while ((*data) && ((*data)->previous->operators == OPERATORS_AND))
			(*data) = (*data)->next;
	}
}

int	has_heredoc(t_cmds *data)
{
	int	i;

	i = 0;
	while (data->in_dir && data->in_dir[i])
	{
		if (data->in_dir[i]->type == 1)
			return (1);
		i++;
	}
	return (0);
}

void	my_wait(void *pid, int reset)
{
	static int	safe;

	if (reset == 1)
		safe = 0;
	if (reset == 1)
		return ;
	waitpid(((t_pid *)pid)->pid, &((t_pid *)pid)->exit, 0);
	if (WIFSIGNALED(((t_pid *)pid)->exit))
	{
		if (safe == 0)
		{
			if (WTERMSIG((t_pid *)pid) == 3)
				ft_putendl_fd("Quit: 3", 2);
			if (WTERMSIG((t_pid *)pid) == 2)
				ft_putstr_fd("\n", 2);
			if (WTERMSIG((t_pid *)pid) == 1)
				((t_pid *)pid)->exit = WTERMSIG(((t_pid *)pid)->exit);
			if (WTERMSIG((t_pid *)pid) == 1)
				return ;
			safe = 1;
		}
		((t_pid *)pid)->exit = WTERMSIG(((t_pid *)pid)->exit);
	}
	if (WIFEXITED(((t_pid *)pid)->exit))
		((t_pid *)pid)->exit = WEXITED(((t_pid *)pid)->exit);
}

void	wait_for_real(t_list *lst, t_execute *exec)
{
	t_list	*head;

	head = lst;
	my_wait(0, 1);
	while (lst)
	{
		my_wait(lst->content, 0);
		lst = lst->next;
	}
	if (head)
		exec->exit = ((t_pid *) ft_lstlast(head)->content)->exit;
	my_wait(0, 1);
}
