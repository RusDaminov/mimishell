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

int		bracket_check(char **str, char **res, int scope);
char	*input_check(char *str, int scope);

int		check_quote(char **str, char **rem);
int		check_redirections(char **str, char **rem);
int		set_incorrect(char **str, char **rem);

int		redirect_size(t_redirect **red);
int		add_redirect(t_redirect ***cur);
int		parse_redirecions(char **str, char **strbuf, t_cmds **cur);

int 	parse_redirections_2(char **str, t_cmds **cur);

int		parse_quotes(char **str, chsr **strbuf);

#endif
