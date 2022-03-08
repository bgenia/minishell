/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex_quoted_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:36:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:12:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ctype.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer_utils.h>

void	lexer_lex_quoted_word(t_lexer *lexer)
{
	char	current;
	size_t	position;
	char	quote;

	position = lexer->position;
	quote = lexer_peek(lexer, 0);
	current = lexer_skip(lexer, 1);
	while (current && current != quote)
		current = lexer_skip(lexer, 1);
	if (current == quote)
	{
		lexer_skip(lexer, 1);
	}
	else
	{
		lexer_set_status(lexer, LEXER_ERROR_UNCLOSED_QUOTE);
		lexer->error_info.expected_quote = quote;
	}
	lexer_add_token(lexer, TOKEN_WORD, position, lexer->position - position);
}
