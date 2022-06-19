/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:36:48 by abernita          #+#    #+#             */
/*   Updated: 2022/05/25 17:36:49 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/builtins.h"

static char	oldenvs(char *env)
{
	char	*chr;
	int		c;

	chr = ft_strchr(env, '=');
	c = 0;
	while (g_ourenv.env[c])
	{
		if (!ft_strncmp(g_ourenv.env[c], env, (chr - env) + 1))
		{
			free(g_ourenv.env[c])
			g_ourenv.env[c] = env;
			return (0);
		}
		c++;
	}
	return (1);
}

static int	printexportnovars(void)
{
	int		i;
	char	*buf;

	i = 0;
	while (g_ourenv.env[i])
	{
		buf = ft_strchr(g_ourenv.env[i], '=');
		printf("declare -x %.*s=\"%s\"\n",
		   (int)(buf - g_ourenv.env[i]), g_ourenv.env[i], buf + 1);
		i++;
	}
	return (0);
}

static int	doexport(char **av)
{
	int		i;
	char	*buf;

	i = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], '='))
		{
			buf = ft_strdup(av[i]);
			if (!buf)
				return (1);
			if (oldenvs(buf))
				if(append_dstring(&g_ourenv.env, buf))
					return (1)
		}
		i++;
	}
	return (0);
}

int	bt_export(char **av)
{
	if (darr_size(av) < 1)
		return (0);
	else if (darr_size(av) == 1)
		return (printexportnovars());
	else if (darr_size(av) >= 2)
		return (doexport(av));
	return (1);
}
