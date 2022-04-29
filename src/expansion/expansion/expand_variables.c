/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:19:40 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 19:43:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include <minishell/expansion/variables.h>
#include <minishell/lexer/token.h>

#include <ft/vector/vector.h>
#include <ft/string/string.h>

void
	expand_variables(t_token **token_vec_ptr)
{
	t_token	*vec_tokens;
	size_t	i;

	vec_tokens = *token_vec_ptr;
	i = 0;
	while (i < ft_vector_get_size(vec_tokens))
	{
		if (vec_tokens[i].is_expandable)
		{
			string_expand_variables(&vec_tokens[i].value);
			vec_tokens[i].length = ft_strlen(vec_tokens[i].value);
		}
		i++;
	}
}
