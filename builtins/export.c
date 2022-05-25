/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:36:48 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 17:36:49 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_export(char **av)
{
	if (darr_size(av) < 1)
		return (0);
	else if (darr_size(av) == 1)
		return (printexportnovars());
	else if (darr_size(av) >= 2)
		return (doexport(av));
	return (1);
}
