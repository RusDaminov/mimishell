/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:12:19 by abernita          #+#    #+#             */
/*   Updated: 2022/06/19 15:12:21 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int bt_env(char **av)
{
    int i;

    i = 0;
    if (!g_ourenv.env)
    {
        ft_putstr_fd("minishell: env: env is empty\n", 2);
        return (1);
    }
    while (g_ourenv.env[i])
    {
        printf("%s\n", g_ourenv.env[i]);
        i++;
    }
    return (0);
    (void)av;
}
