/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:40:40 by jcaron            #+#    #+#             */
/*   Updated: 2023/10/08 18:06:34 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include "str_is.h"


bool	ft_str_is_digit(const char *str)
{
	if (!isdigit(*str))
		return (false);
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_str_is_int(const char *str)
{
	size_t	len;
	bool	is_neg;

	is_neg = false;
	if (*str == '-')
		is_neg = true;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_str_is_digit(str))
		return (false);
	len = strlen(str);
	if (len > 10)
		return (false);
	else if (len == 10)
	{
		if (is_neg && strcmp(STR_MIN_INT, str) < 0)
			return (false);
		else if (!is_neg && strcmp(STR_MAX_INT, str) < 0)
			return (false);
	}
	return (true);
}