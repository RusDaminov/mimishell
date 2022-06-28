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

#include "../includes/minishell.h"

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

int	free_env(void)
{
	int	i;

	i = 0;
	while (g_ourenv.env && g_ourenv.env[i])
		free(g_ourenv.env[i]);
	if (g_ourenv.env)
		free(g_ourenv.env);
	g_ourenv.env = NULL;
	return (0);
}

int	read_env(char **env)
{
	int	i;

	g_ourenv.env = ft_calloc(get_env_size(env) + 2, sizeof(chae *));
	if (!g_ourenv.env)
		return (1);
	i = 0;
	while (env && env[i])
	{
		g_ourenv.env[i] = ft_strdup(env[i]);
		if (!g_ourenv.env[i])
			return (1 + free_env());
		i++;
	}
	g_ourenv.exit_status = 0;
	return (0);
}
