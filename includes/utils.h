/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:20:27 by abernita          #+#    #+#             */
/*   Updated: 2022/06/18 21:20:31 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

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
//int     rm_env(char *str);

#endif
