/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:37:14 by abernita          #+#    #+#             */
/*   Updated: 2022/06/27 22:37:15 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	read_from_stdin(t_cmds *data, int fd[2], int i)
{
	char	*str;

	changetermios(false);
	signal(SIGINT, heredoc_ctlc);
	str = readline("> ");
	while (str && ft_strncmp(data->in_dir[i]->path, str,
			ft_strlen(data->in_dir[i]->path) + 1))
	{
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
		free(str);
		str = readline("> ");
	}
	if (!str)
		return (1);
	if (!data->in_dir[i + 1] && dup2(fd[0], 0) == -1)
	{
		perror("minishell");
		close(fd[0]);
		close(fd[1]);
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

static int	here_doc(t_cmds *data)
{
	int	i;
	int	fd[2];

	i = 0;
	while (data->in_dir && data->in_dir[i])
	{
		if (data->in_dir[i]->type == 1)
		{
			if (pipe(fd) == -1)
			{
				perror("minishell: here_doc");
				return (1);
			}
			if (read_from_stdin(data, fd, i) == 1)
				return (1);
			close(fd[0]);
			close(fd[1]);
		}
		i++;
	}
	return (0);
}

static int	out_directions(t_cmds *data)
{
	int	i;
	int	fd;

	i = 0;
	while (data->out_dir && data->out_dir[i])
	{
		if (data->out_dir[i]->type == 0)
			fd = open(data->out_dir[i]->path, O_RDWR | O_TRUNC, 0644);
		else
			fd = open(data->out_dir[i]->path, O_RDWR
					| O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			perror(data->out_dir[i]->path);
		if (fd == -1)
			return (1);
		if (dup2(fd, 1) == -1)
		{
			perror("minishell");
			close(fd);
			return (1);
		}
		close(fd);
		i++;
	}
	return (0);
}

static int	in_directions(t_cmds *data)
{
	int	i;
	int	fd;

	i = 0;
	while (data->in_dir && data->in_dir[i])
	{
		if (data->in_dir[i]->type == 0)
		{
			fd = open(data->in_dir[i]->path, O_RDONLY);
			if (fd == -1)
			{
				perror(data->in_dir[i]->path);
				return (1);
			}
			if (dup2(fd, 0) == -1)
			{
				close(fd);
				return (1);
			}
			close(fd);
		}
		i++;
	}
	return (0);
}

int	redirect(t_cmds *data, t_execute *exec)
{
	if (!has_heredoc(data) && data->read == 1 && dup2(exec->s_fd, 0) == -1)
		return (execute_child_errors(1, exec, data));
	if (here_doc(data) == 1)
	{
		exec->exit = 1;
		return (1);
	}
	if (in_directions(data) == 1)
	{
		exec->exit = 1;
		return (1);
	}
	if (data->write == 1 && dup2(exec->fd[1], 1) == -1)
		return (execute_child_errors(1, exec, data));
	if (out_directions(data) == 1)
	{
		exec->exit = 1;
		return (1);
	}
	return (0);
}
