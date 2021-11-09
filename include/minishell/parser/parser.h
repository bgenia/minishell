/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:50:21 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/09 20:16:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <minishell/lexer/token.h>

#include <minishell/parser/ast.h>

typedef enum e_parser_status
{
	PARSER_ERROR = -1,
	PARSER_OK
}	t_parser_status;

typedef enum e_parser_error
{
    
}	t_parser_error;

typedef struct s_parser
{
    t_token         *vec_tokens;
	size_t			position;
	size_t			length;
	t_parser_status	status;
	t_parser_error	error;
}	t_parser;

t_parser
parser_create(void);

void
parser_destroy(t_parser *parser);

t_ast_pipeline
*parser_parse(t_parser *parser, t_token *vec_tokens);

t_ast_pipeline
*parser_parse_pipeline(t_parser *parser);
t_ast_command
*parser_parse_command(t_parser *parser);
t_ast_redirection
*pasrer_parse_redirection(t_parser *parser);
char
*parser_parse_word(t_parser *parser);


t_parser_status
parser_raise_error(t_parser *parser, t_parser_error error);

char
parser_peek(t_parser *parser, int offset);
char
parser_skip(t_parser *parser, int count);
bool
parser_is_end(t_parser *parser);
bool
parser_match(t_parser *parser, t_token_type type);
t_token
*parser_consume(t_parser *parser, t_token_type type);

#endif