/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:11:01 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 18:11:04 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	darr_size(char **str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	read_env(char **env)
{
	int	i;

	g_ourenv.env = ft_calloc(get_env_size(env) + 2, sizeof(char *));
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
