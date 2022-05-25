/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:26:57 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 16:26:59 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	parse_redirecions(char **str, char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (dstring_append(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if (**str == '<')
	{
		if (add_redirect(&(*cur)->in_dir))
			return (1);
		if (*((*str) + 1) == '<')
			return (parse_heredoc(str, cur));
		else
			return (parse_leftfile(str, cur));
	}
	else
		return (parse_redirection(str, cur));
	return (0);
}
