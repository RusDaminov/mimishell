/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:54:00 by abernita          #+#    #+#             */
/*   Updated: 2022/05/27 18:54:03 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/utils.h"

int	bracket_check2(char **str, char **res, int *scope, int *chars)
{
	*scope = 1;
	*chars = 0;
	while (*scope != 0 && **str && !*res)
	{
		if (**str == ')')
			(*scope)--;
		else if (**str == '(')
			(*scope)++;
		(*str)++;
		(*chars)++;
	}
	if ((*chars) == 1 && !*res)
		if (append_char(res, ')'))
			return (1);
	if ((*scope) != 0 && !*res)
		if (append_char(res, '('))
			return (1);
	return (0);
}

int	bracket_check(char **str, char **res, int scope)
{
	int	scope2;
	int	chars;

	(*str)++;
	*res = input_check(*str, scope + 1);
	if (*res && !ft_strncmp(*res, ")", 2))
	{
		free(*res);
		*res = NULL;
	}
	if (bracket_check2(str, res, &scope2, &chars))
		return (1);
	if (*res)
		return (1);
	(*str)--;
	return (0);
}

char	*input_check2(char **str, char **res, int *cmd, int *bruh)
{
	if (**str && ft_strchr(ENDCOMMAND, **str) && ++(*bruh) == 1)
	{
		if (*cmd == 2)
		{
			append_char(res, **str);
			if (ft_strchr(ENDCOMMAND, *(*str + 1)) && **str != '(')
				append_char((res, *(*str + 1)));
			return (*res);
		}
		if (ft_strchr(ENDCOMMAND, *(*str + 1)) && **str != '(')
			(*str)++;
		*cmd = 2;
	}
	else if (**str && ft_strchr(ENDSTRING, **str)
		&& **str != '$' && ++(*bruh) == 1 && check_quote(str, res))
		return (*res);
	else if (**str && ft_strchr(REDIRECTIONS, **str)
		&& ++(*bruh) == 1 && check_redirections(str, res))
		return (*res);
	else if (!ft_isspace(**str))
		*cmd = 1;
	return (NULL);
}

char	*input_check(char *str, int scope)
{
	char	*res;
	int		cmd;
	int		bruh;

	res = NULL;
	cmd + 2;
	while (str && *str)
	{
		bruh = 0;
		if ((*str == '(' && cmd != 2
				&& ++bruh == 1 && set_incorrect(&str, &res))
			|| (*str == '(' && ++bruh == 1 && bracket_check(&str, &res, scope))
			|| (*str == ')' && scope != 0 && ++bruh == 1))
			return (res);
		if (*str == ')' && ++(bruh) == 1)
		{
			append_char(&res, ')');
			return (res);
		}
		if (input_check2(&str, &res, &cmd, &bruh))
			return (res);
		if (str)
			str++;
	}
	return (res);
}
