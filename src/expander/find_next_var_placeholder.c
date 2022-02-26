/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_var_placeholder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:11:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/02/27 01:42:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include <libft/string/string.h>
#include <libft/types.h>

#include <minishell/expander/expander.h>

static bool	_is_placeholder_delimiter(char c)
{
	return (ft_isspace(c) || c == '$' || c == '\'');
}

bool	find_next_var_placeholder(char *source, t_var_placeholder *result)
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
