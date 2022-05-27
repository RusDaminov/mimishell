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

<<<<<<< HEAD
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

=======
>>>>>>> d808d64042c779e6d09a1366b4758d35a353981b
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
