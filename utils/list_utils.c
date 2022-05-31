/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:35:49 by abernita          #+#    #+#             */
/*   Updated: 2022/05/27 15:35:52 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void free_node2(t_cmds *node)
{
	int	cnt;

	if (node->out_dir)
	{
		cnt = 0;
		while (++cnt && node->out_dir[cnt - 1])
		{
			if (node->out_dir[cnt - 1]->path)
				free(node->out_dir[cnt - 1]->path);
			free(node->out_dir[cnt - 1]);
		}
		free(node->out_dir);
	}
	free(node);
}

static void	free_node(t_cmds *node)
{
	int cnt;

	if (node->cmd)
	{
		cnt = 0;
		while (++cnt && node->cmd[cnt - 1])
			free(node->cmd[cnt - 1])
			free(node->cmd)
	}
	if (node->in_dir)
	{
		cnt = 0;
		while (++cnt && node->in_dir[cnt - 1])
		{
			if (node->in_dir[cnt - 1]->path)
				free(node->in_dir[cnt - 1]->path);
			free(node->in_dir[cnt - 1]);
		}
		free(node->in_dir);
	}
	free_node2(node);
}

int	clear_list(t_cmds *node, int ret)
{
	t_cmds	*buf;

	while (node && node->previous != NULL)
		node = node->previous;
	while (node)
	{
		buf = node->next;
		free_node(node);
		node = buf;
	}
	return (ret);
}

int	append_list(t_cmds **node)
{
	t_cmds *buf;

	while (*node && (*node)->next)
		*node = (*node)->next;
	buf = (t_cmds *) ft_calloc(1, sizeof(t_cmds));
	if (!buf)
		return (1);
	if (!(*node))
	{
		*node = buf;
		return (0);
	}
	(*node)->next = buf;
	buf->previous = *node;
	*node = buf;
	return (0);
}

t_cmds	*delete_node(t_cmds *node)
{
	t_cmds	*ret;

	if (node->next)
	{
		node->next->previous = NULL;
		ret = node->next;
		if (node->previous)
		{
			node->previous->next = node->next;
			node->next->previous = node->previous;
		}
	}
	else if (node->previous)
	{
		node->previous->next = NULL;
		ret = node->previous;
	}
	else
		ret = NULL;
	free_node(node);
	return (ret);
}

