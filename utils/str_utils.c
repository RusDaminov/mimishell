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

int	append_char(char **str, char c)
{
	char	*buf;
	int 	i;

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
