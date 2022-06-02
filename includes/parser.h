/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:35:09 by abernita          #+#    #+#             */
/*   Updated: 2022/05/31 21:35:13 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

# define REDIRECTIONS "<>"
# define ENDSTRING "\"\'$|"
# define ENDCOMMAND "&|("
# define HEREDOCEND " |&"

t_cmds	*parse(char *str, t_cmds *cur, char *av);

char	*input_check(char *str, int scope);

int		parse_redirecions(char **str, char **strbuf, t_cmds **cur);

#endif
