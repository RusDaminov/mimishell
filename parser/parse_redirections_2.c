/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:26:17 by abernita          #+#    #+#             */
/*   Updated: 2022/06/27 23:26:20 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int parse_rightheredoc(char **str, t_cmds **cur)
{
	int	lst;

	lst = redirect_size((*cur)->out_dir) - 1;
	(*cur)->out_dir[lst]->type = true;
	(*str) += 2;
	while (**str == ' ')
		(*str)++;
	while (!ft_strchr(HEREDOCEND, **str))
	{
		if (**str == '\'' || **str == '\"')
		{
			(*str)++;
			continue ;
		}
		if (append_char(&(*cur)->out_dir[lst]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

static int parse_rightfile(char **str, t_cmds **cur)
{
	int	lst;

	lst = redirect_size((*cur)->out_dir - 1);
	(*cur)->out_dir[lst]->type = false;
	(*str) += 1;
	while (**str == ' ')
		(*str)++;
	while (!ft_strchr(HEREDOCEND, **str) && **str)
	{
		if (**str == '\'' || **str == '\"')
		{
			(*str)++;
			continue;
		}
		if (append_char(&(*cur)->out_dir[lst]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

int parse_redirections_2(char **str, t_cmds **cur)
{
	if (add_redirect(&(*cur)->out_dir))
		return (1);
	if (*((*str) + 1) == '>')
		return (parse_rightheredoc(str, cur));
	else
		return (parse_rightfile(str, cur));
}
