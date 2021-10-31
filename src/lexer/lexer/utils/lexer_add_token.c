/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:44:42 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/31 15:15:51 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/types.h>
#include <libft/string/string.h>
#include <libft/vector/vector.h>

#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer.h>
#include <minishell/lexer/lexer_utils.h>

void	lexer_add_token(
	t_lexer *lexer,
	t_token_type type,
	size_t position,
	size_t length
)
{
	t_token	token;

	token = (t_token){.type = type, .position = position, .length = length};
	if (is_redirection(type))
	{
		if (ft_isdigit(lexer->source[position]))
			token.fd = lexer->source[position] - '0';
		else
			token.fd = -1;
	}
	if (type == TOKEN_WORD)
	{
		token.is_expandable = true;
		token.is_quoted = is_quote(lexer->source[position]);
		if (token.is_quoted)
		{
			token.is_expandable = lexer->source[position] == '"';
			token.position += 1;
			token.length -= 1;
			if (is_quote(lexer->source[position + token.length]))
				token.length -= 1;
		}
	}
	token.value = ft_substr(lexer->source, token.position, token.length);
	*(t_token *)ft_vector_push_back(lexer->vec_tokens) = token;
}
