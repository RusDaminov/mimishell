/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:09:25 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 17:09:27 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../builtins.h"

static char	set_newenv(char *env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = NULL;
	while (g_ourenv.env && g_ourenv.env[i])
	{
		if (!(!ft_strncmp(g_ourenv.env[i], env,
						  ft_strchr(g_ourenv.env[i], '=') - g_ourenv.env[i])))
		{
			if (dstring_append(&new_env, g_ourenv.env[i]))
				return (1);
		}
		else
			free(g_ourenv.env[i]);
		i++;
	}
	free(g_ourenv.env);
	g_ourenv.env = new_env;
	return (0);
}

int	bt_unset(char *av)
{
	int	i;

	if (darr_size(av) >= 2)
	{
		i = 1;
		while (av[i])
		{
			if (set_newenv(av[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
