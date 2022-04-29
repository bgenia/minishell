/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_var_placeholder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:11:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 19:52:48 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include <ft/string/string.h>
#include <ft/ctype.h>

#include <minishell/expansion/variables.h>

static bool
	_is_placeholder_delimiter(char c)
{
	return (ft_isspace(c) || c == '$' || c == '\'');
}

bool
	find_next_var_placeholder(char *source, t_var_placeholder *result)
{
	char	*placeholder;
	size_t	i;

	placeholder = ft_strchr(source, '$');
	if (!placeholder)
		return (false);
	i = 1;
	while (placeholder[i] && !_is_placeholder_delimiter(placeholder[i]))
		i++;
	if (i == 1)
		return (false);
	result->length = i;
	result->position = placeholder - source;
	return (true);
}
