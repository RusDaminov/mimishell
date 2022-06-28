/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:42:15 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 17:42:17 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_builtins
{
	char	*name;
	int		(*func)(char *av);
}	t_builtins;

int	bt_cd(char **av);
int	bt_echo(char **av);
int	bt_env(char **av);
int	bt_exit(char **av);
int	bt_export(char **av);
int	bt_pwd(char **av);
int	bt_unset(char *av);
int	bt_true(char **av);
int	bt_false(char **av);

#endif
