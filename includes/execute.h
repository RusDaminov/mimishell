/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:23:28 by abernita          #+#    #+#             */
/*   Updated: 2022/06/19 22:23:31 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

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

unsigned char	execute(t_cmds *data);
int				check_builtin(t_cmds *cmd, t_execute *exec);
#endif
