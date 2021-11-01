/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_simple_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:16:22 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/01 12:28:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/vector/vector.h>
#include <libft/string/string.h>
#include <libft/array.h>

#include <minishell/lexer/token.h>

static size_t	_insert_new_tokens(
	t_token **token_vec_ptr,
	char **words,
	size_t i,
	t_token src_token
)
{
	size_t	word_count;
	size_t	j;
	t_token	*tokens;

	word_count = ft_arrlen(words, sizeof(*words));
	tokens = ft_vector_insert_many_at(token_vec_ptr, i, word_count);
	j = 0;
	while (j < word_count)
	{
		tokens[j] = src_token;
		tokens[j].value = words[j];
		j++;
	}
	return (word_count);
}

void	split_simple_words(t_token **token_vec_ptr)
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
