/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:44:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 15:29:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/types.h>
#include <libft/string/string.h>
#include <libft/vector/vector.h>

#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer.h>
#include <minishell/lexer/lexer_utils.h>

static void
	_normalize_redirection(t_lexer *lexer, t_token *token)
{
	if (ft_isdigit(lexer->source[token->position]))
		token->fd = lexer->source[token->position] - '0';
	else
		token->fd = -1;
}

// Cringe
static bool
	_bruh_norme_fix(t_lexer *lexer, size_t position)
{
	return (!lexer->heredoc_mode && lexer->source[position] == '"');
}

static void
	_normalize_word(t_lexer *lexer, t_token *token)
{
	token->is_expandable = !lexer->heredoc_mode;
	token->is_quoted = is_quote(lexer->source[token->position]);
	if (token->is_quoted)
	{
		token->is_expandable = _bruh_norme_fix(lexer, token->position);
		token->position += 1;
		token->length -= 1;
		if (is_quote(lexer->source[token->position + token->length - 1]))
			token->length -= 1;
	}
}

void
	lexer_add_token(
		t_lexer *lexer,
		t_token_type type,
		size_t position,
		size_t length
	)
{
	t_token	token;

	token = (t_token){.type = type, .position = position, .length = length};
	if (is_redirection(type))
		_normalize_redirection(lexer, &token);
	if (type == TOKEN_RHD)
		lexer->heredoc_mode = true;
	else if (type != TOKEN_WORD && lexer->heredoc_mode)
		lexer->heredoc_mode = false;
	if (type == TOKEN_WORD)
		_normalize_word(lexer, &token);
	token.value = ft_substr(lexer->source, token.position, token.length);
	*(t_token *)ft_vector_push_back(lexer->vec_tokens) = token;
}
