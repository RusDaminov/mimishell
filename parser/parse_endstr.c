/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_endstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:44:36 by abernita          #+#    #+#             */
/*   Updated: 2022/06/27 23:44:38 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	parse_variable2(char **str,
						char **strbuf, char **var_name, char **variable)
{
	if (!*var_name && *(*str + 1) == '?')
	{
		(*str)++;
		*variable = ft_itoa(g_ourenv.exit_status);
		if (!(*variable))
			return (1);
		if (append_string(strbuf, *variable))
			return (1);
	}
	else if (*var_name)
	{
		if (get_env_value(*var_name))
			*variable = ft_strdup(get_env_value(*var_name));
		else
			append_string(variable, '\0');
		free(*var_name);
		if (!(*variable))
			return (1);
		if (append_string(strbuf, *variable))
			return (1);
	}
	free(*variable);
	return (0);
}

static int	parse_variable(char **str, char **strbuf)
{
	char	*var_name;
	char	*variable;

	var_name = NULL;
	variable = NULL;
	(*str)++;
	if (**str && ft_strchr("\'\"", **str) && (*str)--)
		return (0);
	while ((**str == '_' || ft_isalnum(**str)) && **str)
	{
		if (append_char(&var_name, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (parse_variable2(str, strbuf, &var_name, &variable));
}

static int	parse_dbl(char **str, char **strbuf)
{
	(*str)++;
	if (append_char(strbuf, '\0'))
		return (1);
	while (**str != '\"')
	{
		if (**str == '\0')
			return (1);
		else if (**str != '$' && append_char(strbuf, **str))
			return (1);
		else if (**str == '$' && append_char(strbuf, **str))
			return (1);
		(*str)++;
	}
	return (0);
}

static int	parse_sngl(char **str, char **strbuf)
{
	(*str)++;
	if (append_char(strbuf, '\0'))
		return (1);
	while (**str != '\'')
	{
		if (**str == '\0')
			return (1);
		else if (append_char(strbuf, **str))
			return (1);
		(*str)++;
	}
	return (0);
}

int	parse_quotes(char **str, char **strbuf)
{
	if (**str == '\'')
		return (parse_sngl(str, strbuf));
	else if (**str == '\"')
		return (parse_dbl(str, strbuf));
	else
		return (parse_variable(str, strbuf));
}
