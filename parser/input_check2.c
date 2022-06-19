/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:38:12 by abernita          #+#    #+#             */
/*   Updated: 2022/06/19 14:38:14 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	check_quote(char **str, char **rem)
{
	(*str)++;
	if (*(*str - 1) == '\'')
	{
		while (**str && **str != '\'')
			(*str)++;
		if (!**str)
			append_char(rem, '\'');
	}
	else if (*(*str - 1) == '\"')
	{
		while (**str && **str != '\"')
			(*str)++;
		if (!**str)
			append_char(rem, '\"');
	}
	if (*rem)
		return (1);
	return (0);
}

int	check_redirections(char **str, char **rem)
{
	(*str)++;
	if (**str == *(*str - 1))
		(*str)++;
	while (ft_isspace(**str);
		(*str)++;
	if (!**str)
	{
		*rem = ft_strdup("newline");
		return (1);
	}
	if (ft_strchr(ENDCOMMAND, **str) || ft_strchr(REDIRECTIONS, **str))
	{
		append_char(rem, **str);
		if ((**str == '&' || **str == '|') && *(*str + 1) == **str)
			append_char(rem, **str);
		return (1);
	}
	return (0);
}

static void	set_incorrect2(char **str, char **rem)
{
	while (**str && !ft_strchr(ENDCOMMAND, **str)
		&& !(ft_strchr(ENDSTRING, **str) && **str != '$')
		&& **str != ')' && !ft_isspace(**str))
	{
		append_char(rem, **str);
		(*str)++;
	}
}

int	set_incorrect(char **str, char **rem)
{
	char	pep;

	(*str)++;
	while (ft_isspace(**str))
		(*str)++;
	if (ft_strchr(ENDCOMMAND, *str))
	{
		append_char(rem, **str);
		if (ft_strchr(ENDCOMMAND, *(*str + 1)))
			append_char(rem, **str);
	}
	else if (**str == '\"' || **str == '\'')
	{
		pep = **str;
		append_char(rem, **str);
		while (*(++(*str)) && **str != pep)
			append_char(rem, **str);
		append_char(rem, **str);
	}
	else
		set_incorrect2(str, rem);
	(*str)--;
	return (1);
}
