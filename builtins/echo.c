/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:26:45 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 16:26:49 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../builtins.h"

int	bt_echo(char **av)
{
	bool	nl;

	if (!av || !av[0])
	{
		ft_putstr_fd("Echo input error\n", 2);
		return (1);
	}
	nl = 0;
	av++;
	if (av[0] && !ft_strncmp(av[0], "-n", 3))
	{
		nl = 1;
		av++;
	}
	while (*av)
	{
		ft_putstr_fd(*av, 1);
		av++;
		if (*av)
			ft_putchar_fd(' ', 1);
	}
	if (nl == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
