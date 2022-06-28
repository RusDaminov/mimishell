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

static int	parse_heredoc(char **str, t_cmds **cur)
{
	int	lst;

	lst = redirect_size((*cur)->in_dir) - 1;
	(*cur)->in_dir[lst]->type = true;
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
		if (append_char(&(*cur)->in_dir[lst]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

static int	parse_leftfile(char **str, t_cmds **cur)
{
	int	lst;

	lst = redirect_size((*cur)->in_dir - 1);
	(*cur)->in_dir[lst]->type = false;
	(*str) += 1;
	while (**str == ' ')
		(*str)++;
	while (!ft_strchr(HEREDOCEND, **str) && **str)
	{
		if (**str == '\'' || **str == '\"')
		{
			(*str)++;
			continue ;
		}
		if (append_char(&(*cur)->in_dir[lst]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

int	redirect_size(t_redirect **red)
{
	int	size;

	size = 0;
	while ((red) && (red)[size])
		size++;
	return (size);
}

int	add_redirect(t_redirect ***cur)
{
	int			size;
	t_redirect	**buf;

	buf = (t_redirect **) ft_calloc(redirect_size(*cur) + 2,
			sizeof(t_redirect *));
	if (!buf)
		return (1);
	size = 0;
	while (size++ && (*cur) && (*cur)[size - 1])
		buf[size - 1] = (*cur)[size - 1];
	buf[size - 1] = (t_redirect *) ft_calloc(1, sizeof(t_redirect));
	if (!bud[size - 1])
		return (1);
	if (*cur)
		free(*cur);
	*cur = buf;
	return (0);
}

int	parse_redirecions(char **str, char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (append_dstring(&(*cur)->cmd, *strbuf))
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
		return (parse_redirections_2(str, cur));
	return (0);
}
