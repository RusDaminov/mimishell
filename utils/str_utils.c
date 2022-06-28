/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:07:19 by abernita          #+#    #+#             */
/*   Updated: 2022/06/02 23:07:20 by abernita         ###   ########.fr       */
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

int	append_char(char **str, char c)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(ft_strlen(*str) + 2);
	if (!buf)
		return (1);
	i = 0;
	while (*str && (*str)[i])
	{
		buf[i] = (*str)[i];
		i++;
	}
	buf[i] = c;
	buf[i + 1] = '\0';
	if (*str)
		free(*str);
	*str = buf;
	return (0);
}

int	append_dstring(char ***org, char *str)
{
	char	**buf;
	int		i;

	buf = (char **)malloc((darr_size(*org) + 2) * sizeof(char *));
	if (!buf)
		return (1);
	i = 0;
	while (*org && (*org)[i])
	{
		buf[i] = (*org)[i];
		i++;
	}
	buf[i] = str;
	buf[i + 1] = NULL;
	if (*org)
		free(*org);
	*org = buf;
	return (0);
}

int	append_string(char **org, char *str)
{
	char	*buf;
	int		i;
	int		j;

	buf = (char *) ft_calloc(1, ft_strlen(*org) + ft_strlen(str) + 2);
	if (!buf)
		return (0);
	i = 0;
	j = 0;
	while (*org && (*org)[i])
	{
		buf[i] = (*org)[j];
		i++;
	}
	j = i;
	while (str && str[i - j])
	{
		buf[i] = str[i - j];
		i++;
	}
	if (*org)
		free(*org);
	*org = buf;
	return (0);
}
