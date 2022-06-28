/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_endcmd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:01:28 by abernita          #+#    #+#             */
/*   Updated: 2022/06/28 00:02:02 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	parse_or(char **str, char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (append_dstring(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if ((*cur)->cmd)
		(*cur)->operators = OPERATORS_OR;
	if ((*cur)->cmd && append_list(cur))
		return (1);
	if ((*cur)->previous)
		(*cur)->previous->operators = OPERATORS_OR;
	*str += 1;
	return (0);
}
