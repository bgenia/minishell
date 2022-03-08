/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 23:25:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stddef.h>
# include <stdbool.h>

# include <minishell/lexer/token.h>

typedef enum e_lexer_status
{
	LEXER_OK,
	LEXER_ERROR_NO_SOURCE,
	LEXER_ERROR_UNCLOSED_QUOTE
}	t_lexer_status;

typedef struct s_lexer_error_info
{
	char	expected_quote;
}	t_lexer_error_info;

typedef struct s_lexer
{
	char				*source;
	size_t				position;
	size_t				length;
	bool				heredoc_mode;
	t_token				**vec_tokens;
	t_lexer_status		status;
	t_lexer_error_info	error_info;
}	t_lexer;

// Create / Destroy

t_lexer
lexer_create(t_token **vec_tokens);
void
lexer_destroy(t_lexer *lexer);

// External API

t_lexer_status
lexer_analyze(t_lexer *lexer, char *source);

// Subroutines
void
lexer_lex_redirection(t_lexer *lexer);
void
lexer_lex_pipe(t_lexer *lexer);
void
lexer_lex_simple_word(t_lexer *lexer);
void
lexer_lex_quoted_word(t_lexer *lexer);
void
lexer_lex_whitespace(t_lexer *lexer);

// Internal API
void
lexer_add_token(
	t_lexer *lexer,
	t_token_type type,
	size_t position,
	size_t length
	);

t_lexer_status
lexer_set_status(t_lexer *lexer, t_lexer_status status);

char
lexer_peek(t_lexer *lexer, int offset);
char
lexer_skip(t_lexer *lexer, int count);
bool
lexer_is_end(t_lexer *lexer);

#endif
