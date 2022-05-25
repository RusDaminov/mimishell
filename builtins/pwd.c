/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:06:22 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 17:06:25 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../builtins.h"

int	bt_pwd(char **av)
{
	char	str[4096];

	if (!getcwd(str, 4096))
	{
		perror("minishell");
		return (1);
	}
	printf("%s\n", str);
	return (0);
	(void)av;
}
