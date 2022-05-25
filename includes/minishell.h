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
# include "builtins.h"

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


#endif
