/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_endcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:00:49 by abernita          #+#    #+#             */
/*   Updated: 2022/06/28 00:00:51 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	parse_and(char **str, char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (append_dstring(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if ((*cur)->cmd)
		(*cur)->operators = OPERATORS_AND;
	if ((*cur)->cmd && append_list(cur))
		return (1);
	if ((*cur)->previous)
		(*cur)->previous->operators = OPERATORS_AND;
	*str += 1;
	return (0);
}

static int	parse_pipe(char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (append_dstring(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if ((*cur)->cmd)
	{
		if ((*cur)->previous)
			(*cur)->previous->write = true;
		(*cur)->read = true;
	}
	if ((*cur)->cmd)
		(*cur)->write = true;
	if ((*cur)->cmd && append_list(cur))
		return (1);
	(*cur)->read = true;
	return (0);
}

static int	parse_brackets2(char **str, char **buf, t_cmds **cur)
{
	int	scope;

	scope = 0;
	*buf = NULL;
	while (*str && (*(++(*str)) != ')' || scope != 0))
	{
		if (append_char(buf, **str))
			return (1);
		if (**str == '(')
			scope++;
		if (**str == ')')
			scope --;
	}
	if (append_dstring(&(*cur)->cmd, *buf))
		return (1);
	if (append_list(cur))
		return (1);
	return (0);
}

static int	parse_brackets(char **str, char **strbuf, t_cmds **cur, char *av)
{
	char	*buf;

	if (*strbuf)
	{
		if (append_dstring(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if ((*cur)->cmd && append_list(cur))
		return (1);
	buf = ft_strdup(av);
	if (!buf)
		return (1);
	if (append_dstring(&(*cur)->cmd, buf))
		return (1);
	return (parse_brackets2(str, &buf, cur));
}

int	parse_endcmds(char **str, char **strbuf, t_cmds **cur, char *av)
{
	if (**str == '(')
		return (parse_brackets(str, strbuf, cur, av));
	if (**str == '|' && *(*str + 1) != '|')
		return (parse_pipe(strbuf, cur));
	if (**str == '|')
		return (parse_or(str, strbuf, cur));
	if (**str == '&' && *(*str + 1) != '&')
		return (parse_and(str, strbuf, cur));
	else
		return (append_char(strbuf, **str));
}
