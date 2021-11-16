/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_adjacent_words.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:16:22 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/16 19:30:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/vector/vector.h>
#include <libft/string/string.h>
#include <libft/string/format.h>

#include <minishell/lexer/token.h>

static void	_merge_tokens(t_token *dst, t_token *other)
{
	char	*new_value;

	new_value = ft_strjoin(dst->value, other->value);
	free(dst->value);
	dst->value = new_value;
	dst->length += other->length;
	dst->is_quoted = other->is_quoted;
}

void	merge_adjacent_words(t_token **token_vec_ptr)
{
	size_t	i;
	t_token	*prev;
	t_token	*current;

	i = 1;
	while (i < ft_vector_get_size(*token_vec_ptr))
	{
		prev = &(*token_vec_ptr)[i - 1];
		current = &(*token_vec_ptr)[i];
		if (prev->type == TOKEN_WORD && current->type == TOKEN_WORD)
		{
			_merge_tokens(prev, current);
			free(current->value);
			ft_vector_remove_at(token_vec_ptr, i);
		}
		else
			i++;
	}
}
