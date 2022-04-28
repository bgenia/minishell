/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:39:30 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/string/string.h>

#include <minishell/expander/expander.h>
#include <minishell/lexer/token.h>

void
	expand_tokens(t_token *vec_tokens)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(vec_tokens))
	{
		if (vec_tokens[i].is_expandable)
		{
			expand_env_variables(&vec_tokens[i].value);
			vec_tokens[i].length = ft_strlen(vec_tokens[i].value);
		}
		i++;
	}
}
