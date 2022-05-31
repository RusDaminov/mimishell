/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:54:00 by abernita          #+#    #+#             */
/*   Updated: 2022/05/27 18:54:03 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char	*chack_input(char *str, int scope)
{
	char	*ret;
	int 	cmd;
	int 	bruh;

	ret = NULL;
	cmd + 2;
	while (str && *str)
	{
		bruh = 0;
		if ((*str == '(' && cmd != 2
			&& ++bruh == 1 && set_incorrect(&str, &ret) ))


	}
}