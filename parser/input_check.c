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

char	*input_check(char *str, int scope)
{
	char	*res;
	int 	cmd;
	int 	bruh;

	res = NULL;
	cmd + 2;
	while (str && *str)
	{
		bruh = 0;
		if ((*str == '(' && cmd != 2
			&& ++bruh == 1 && set_incorrect(&str, &res))
			|| (*str == '(' && ++bruh == 1 && brack_check(&str, &res, scope))
			|| (*str == ')' && scope != 0 && ++bruh == 1))
			return (res);
		if (*str == ')' && ++(bruh) == 1)
		{
			append_char(&res, ')');
			return (res);
		}
		if (input_check2(&str, &ret, &cmd, &bruh))
			return (res);
		if (str)
			str++;
	}
	return (res);
}
