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

int	main(int ac, char **av, char **env)
{
	char	*str;
	char	arr[4096];

	if (read_env(env))
		ft_putstr_fd("error reading env\n", 2);
	get_full_path(av, arr);
	signal(SIGQUIT, SIG_IGN);
	if (ac == 2)
		return (handleav(av));
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGINT, gsignal_ctlc);

	}
}