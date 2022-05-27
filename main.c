/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:10:58 by abernita          #+#    #+#             */
/*   Updated: 2022/05/19 15:11:02 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	get_full_path(char **av, char arr[4096])
{
	if ((*av)[0] != '.')
		return (0);
	if (getcwd(arr, 4096) == 0)
		return (1);
	ft_strlcpy(arr + ft_strlen(arr), "/", 2);
	ft_strlcpy(arr + ft_strlen(arr), av[0], ft_strlen(av[0]) + 1);
	av[0] = arr;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	char	arr[4096];

	if (read_env(env))
		ft_putstr_fd("error reading env\n", 2);
	get_full_path(av, arr);
	signal(SIGQUIT, SIG_IGN);
	if (ac == 2)
		return (handlearg(av));
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGINT, gsignal_ctlc);

	}
}