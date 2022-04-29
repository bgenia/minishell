/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_simple_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:16:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/vector/vector.h>
#include <ft/string/string.h>
#include <ft/array.h>

#include <minishell/lexer/token.h>

static size_t
	_insert_new_tokens(
		t_token **token_vec_ptr,
		char **words,
		size_t i,
		t_token src_token
	)
{
	size_t	word_count;
	size_t	j;
	size_t	k;
	t_token	*tokens;

	word_count = ft_arrlen(words, sizeof(*words));
	tokens = ft_vector_insert_many_at(token_vec_ptr, i, word_count * 2 - 1);
	j = 0;
	k = 0;
	while (j < word_count * 2 - 1)
	{
		tokens[j] = src_token;
		if (j % 2 == 0)
		{
			tokens[j].value = words[k++];
		}
		else
		{
			tokens[j].type = TOKEN_SPACE;
			tokens[j].value = NULL;
			tokens[j].length = 0;
		}
		j++;
	}
	return (j);
}

void
	split_simple_words(t_token **token_vec_ptr)
{
	size_t	i;
	t_token	*current;
	t_token	copy;
	char	**words;

	i = 0;
	while (i < ft_vector_get_size(*token_vec_ptr))
	{
		current = &(*token_vec_ptr)[i];
		if (current->type == TOKEN_WORD && !current->is_quoted
			&& ft_strchr(current->value, ' '))
		{
			words = ft_split(current->value, ' ');
			copy = *current;
			ft_vector_remove_at(token_vec_ptr, i);
			i += _insert_new_tokens(token_vec_ptr, words, i, copy);
			free(copy.value);
			free(words);
		}
		else
			i++;
	}
}
