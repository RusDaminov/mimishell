/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:15 by abernita          #+#    #+#             */
/*   Updated: 2022/05/19 16:11:17 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	parse_space(char **strbuf, t_cmds *cur)
{
	if (!(*strbuf))
		return (0);
	if (append_dstring(&cur->cmd, *strbuf))
		return (1);
	*strbuf = NULL;
	return (0);
}

static int	parse_2(char *str, t_cmds *cur, int fc, char **strbuf)
{
	if (ft_strchr(REDIRECTIONS, **str) && ++fc
		&& parse_redirecions(str, strbuf, &cur))
		return (1);
	else if (**str == '*' && ++fc && parse_asterix(str, strbuf, &cur))
		return (1);
	else if (!fc && append_char(strbuf, **str))
		return (1);
	return (0);
}

t_cmds	*parse(char *str, t_cmds *cur, char *av)
{
	char	*strbuf;
	int		fc;

	strbuf = NULL;
	while (str && *(str))
	{

		fc = 0;
		if (ft_strchr(ENDSTRING, *str) && ++fc && parse_quotes(&str, &strbuf))
			return ((void *)(size_t)clear_list(cur, 0));
		else if ()
			return ((void *)(size_t)clear_list(cur, 0));
		else if (ft_strchr(ENDCOMMAND, *str) && ++fc
			&& parse_endcommands(&str, &strbuf, &cur, av))
			return ((void *)(size_t)clear_list(cur, 0));
		else if (parse_2(str, cur, fc, &strbuf))
			return ((void *)(size_t)clear_list(cur, 0));
		str++;
	}
	if (strbuf)
		if (append_dstring(&cur->cmd, strbuf))
			return ((void *)(size_t)clear_list(cur, 0));
	return (find_listhead(cur));
}
