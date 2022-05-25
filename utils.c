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

#include "includes/utils.h"

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