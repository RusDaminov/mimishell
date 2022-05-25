/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:00:36 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 18:00:50 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*get_env_value(char *str)
{
	int	i;

	i = 0;
	while (g_ourenv.env && g_ourenv.env[i] && str)
	{
		if (!ft_strncmp(g_ourenv.env[i], str,
				ft_strchr(g_ourenv.env[i], '=') - g_ourenv.env[i]))
			return (ft_strchr(g_ourenv.env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

static int	get_env_size(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (1);
}
