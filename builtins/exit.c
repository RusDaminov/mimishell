/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:46:30 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 17:46:32 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/builtins.h"

static void	ft_check_if_int(char **av, int *ret)
{
	int	c;

	c = 0;
	*ret = 0;
	while (darr_size(av) >= 2 && av[1][c])
	{
		if (!ft_isdigit(av[1][c]) && av[1][c] != '-' && av[1][c] != '+')
		{
			*ret = 255;
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			break ;
		}
		c++;
	}
}

int	bt_exit(char **av)
{
	int	res;

	ft_check_if_int(av, &res);
	if (darr_size(av) > 2 && res != 255)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	clear_history();
	if (darr_size(av) > 2 && res != 255)
		res = ft_atoi(av[1]);
	ft_putstr_fd("exit\n", 2);
	exit(res);
	return (0);
}
