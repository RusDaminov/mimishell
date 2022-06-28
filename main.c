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

void	exit_free(t_cmds *cmd, char *str, bool status)
{
	static t_cmds	*data;
	static char 	*s;

	if (status == 0)
	{
		data = cmd;
		s = str;
	}
	else
	{
		clear_history();
		clear_list(data, 0);
		free(s);
	}
}

static int	handleinput(char *str, char *av)
{
	t_cmds	*cmds;
	char	*symbol;

	symbol = input_check(str, 0);
	if (!symbol)
	{
		cmds = NULL;
		if (append_list((&cmds)))
			return (1);
		cmds = parse(str, cmds, av);
		if (!cmds)
			return (1);
		if (find_last(cmds)->cmd == NULL)
			cmds = delete_node(find_last(cmds));
		cmds = find_listhead(cmds);
		exit_free(cmds, str, 0);
		g_ourenv.exit_status = execute(cmds);
		clear_list(cmds, 0);
		return (0);
	}
	ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
	ft_putstr_fd(symbol, 2);
	ft_putstr_fd("\'\n", 2);
	free(symbol);
	return (0);
}

static int	handlearg(char *av[])
{
	t_cmds	*cmds;

	cmds = NULL;
	if (append_list(&cmds))
		return (1);
	cmds = parse(av[1], cmds, av[0]);
	if (!cmds)
		return (1);
	if (find_last(cmds)->cmd == NULL)
		cmds = delete_node(find_last(cmds));
	cmds = find_listhead(cmds);
	return (clear_list(cmds, ((int)execute(cmds))));
}

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

int	main(int ac, char *av[], char **env)
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
		changetermios(false);
		str = readline("minishell \x1b[s");
		if (str == NULL && write(1, "\x1b[uexit\n", 9) && !changetermios(true))
			exit(0);
		if (handleinput(str, av[0]))
			ft_putstr_fd("minishell: malloc error\n", 2);
		if (str && str[0])
			add_history(str);
		free(str);
	}
	return (0);
}
