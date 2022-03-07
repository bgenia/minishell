/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:50:21 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 16:21:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <minishell/lexer/token.h>

#include <minishell/parser/ast.h>

typedef enum e_parser_status
{
	PARSER_OK,
	PARSER_ERROR_BAD_SYNTAX
}	t_parser_status;

typedef struct s_parser_error_info
{
	t_token_type	expected;
	t_token			got;
}	t_parser_error_info;

typedef struct s_parser
{
	t_token				*vec_tokens;
	size_t				position;
	size_t				length;
	t_ast				*ast;
	t_parser_status		status;
	t_parser_error_info	error_info;
}	t_parser;

t_parser
parser_create(t_ast *ast);

void
parser_destroy(t_parser *parser);

t_parser_status
parser_parse(t_parser *parser, t_token *vec_tokens);

t_parser_status
parser_parse_pipeline(t_parser *parser, t_ast_pipeline *result);
t_parser_status
parser_parse_command(t_parser *parser, t_ast_command *result);
t_parser_status
pasrer_parse_redirection(t_parser *parser, t_ast_redirection *result);
t_parser_status
parser_parse_word(t_parser *parser, char **result);

t_parser_status
parser_set_status(t_parser *parser, t_parser_status status);

t_token
parser_peek(t_parser *parser, int offset);
t_token
parser_skip(t_parser *parser, int count);
bool
parser_is_end(t_parser *parser);
bool
parser_match(t_parser *parser, t_token_type type);
bool
parser_consume(t_parser *parser, t_token_type type);

#endif
