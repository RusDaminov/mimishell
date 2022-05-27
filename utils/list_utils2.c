/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:30:13 by abernita          #+#    #+#             */
/*   Updated: 2022/05/27 18:30:15 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_cmds	*find_listhead(t_cmds *node)
{
	while (node && node->previous)
		node = node->previous;
	return (node);
}

t_cmds	*find_last(t_cmds *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}
