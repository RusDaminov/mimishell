/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:11:15 by abernita          #+#    #+#             */
/*   Updated: 2022/05/19 15:11:17 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

static int	update_pwd(char *str, char *arr[3])
{
	char	pwd[4096];

	if (get_env_value("PWD"))
	{
		if (!getcwd(pwd, 4096))
		{
			perror("mimishell: cd");
			return (1);
		}
		str = ft_strjoin("PWD=", pwd);
		if (!str)
		{
			perror("mimishell: cd");
			return (1);
		}
		arr[1] = str;
		if (bt_export(arr) == 1)
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}

static int	update_old_pwd(void)
{
	char	*str;
	char	*arr[3];

	arr[0] = "export";
	arr[2] = 0;
	if (get_env_value("OLDPWD"))
	{
		if (get_env_value("PWD"))
			str = ft_strjoin("OLDPWD=", get_env_value("PWD"));
		else
			str = ft_strdup("OLDPWD=");
		if (!str)
		{
			perror("mimishell: cd");
			return (1);
		}
		arr[1] = str;
		if (bt_export(arr) == 1)
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (update_pwd(0, arr));
}

int	bt_cd(char **av)
{
	av++;
	if (!*av)
	{
		if (!get_env_value("HOME"))
		{
			ft_putstr_fd("mimishell: cd: HOME not set\n", 2);
			return (1)
		}
		if (chdir(get_env_value("HOME")) == -1)
		{
			ft_putstr_fd("mimishell: cd: ", 2);
			perror(get_env_value("HOME"));
			return (1)
		}
	}
	else if (chdir(*av) == -1)
	{
		ft_putstr_fd("mimishell: cd: ", 2);
		perror(*av);
		return (1)
	}
	return (update_old_pwd());
}