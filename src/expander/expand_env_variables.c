/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:19:40 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:19:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include <minishell/expander/expander.h>
#include <minishell/shell/shell.h>

#include <libft/string/string.h>
#include <libft/string/format.h>
#include <libft/memory/memory.h>
#include <libft/system/env.h>

static char
	*_get_ph_value(t_var_placeholder *ph, char *source)
{
	char	*ph_var;
	char	*ph_value;

	ph_var = ft_substr(source, ph->position + 1, ph->length - 1);
	if (ft_streq(ph_var, "?"))
		ph_value = shell_get_state()->last_status_string;
	else
		ph_value = ft_getenv(ph_var);
	free(ph_var);
	return (ph_value);
}

static char
	*_create_new_value(char *old_value, t_var_placeholder *ph, char *ph_value)
{
	size_t	result_size;
	char	*result;

	result_size = sizeof(*result) * (ph->position + ft_strlen(ph_value)
			+ (ft_strlen(old_value) - ph->position - ph->length) + 1);
	result = ft_malloc(result_size);
	ft_format(result, result_size, "%S%s%S",
		ft_substr(old_value, 0, ph->position),
		ph_value,
		ft_substr(old_value, ph->position + ph->length,
			ft_strlen(old_value) - ph->position - ph->length)
		);
	return (result);
}

void
	expand_env_variables(char **source)
{
	t_var_placeholder	ph;
	char				*ph_value;
	char				*new_value;

	while (find_next_var_placeholder(*source, &ph))
	{
		ph_value = _get_ph_value(&ph, *source);
		if (ph_value == NULL)
			ph_value = "";
		new_value = _create_new_value(*source, &ph, ph_value);
		free(*source);
		*source = new_value;
	}
}
