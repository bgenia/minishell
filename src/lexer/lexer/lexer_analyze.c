/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analyze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:05:20 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/10 21:32:20 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/types.h>
#include <libft/string/string.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer_utils.h>

t_lexer_status	lexer_analyze(t_lexer *lexer, char *source)
{
	char	current;

	if (!source)
		return (lexer_set_status(lexer, LEXER_ERROR_NO_SOURCE));
	lexer->source = source;
	lexer->position = 0;
	lexer->length = ft_strlen(source);
	current = lexer_peek(lexer, 0);
	while (!lexer_is_end(lexer) && lexer->status == LEXER_OK)
	{
		if (ft_isdigit(current) && is_redirection_char(lexer_peek(lexer, 1)))
			lexer_lex_redirection(lexer);
		else if (is_redirection_char(current))
			lexer_lex_redirection(lexer);
		else if (current == '|')
			lexer_lex_pipe(lexer);
		else if (is_quote(current))
			lexer_lex_quoted_word(lexer);
		else if (!ft_isspace(current))
			lexer_lex_simple_word(lexer);
		else
			lexer_lex_whitespace(lexer);
		current = lexer_peek(lexer, 0);
	}
	return (lexer->status);
}
