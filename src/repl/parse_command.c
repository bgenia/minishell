/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:29:18 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 16:44:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/vector/vector.h>
#include <libft/system/env.h>
#include <libft/terminal/termdefs.h>
#include <libft/string/string.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

#include <minishell/parser/ast.h>
#include <minishell/parser/parser.h>
#include <minishell/parser/parser_utils.h>

#include <minishell/expander/expander.h>
#include <minishell/preparser/preparser.h>

#include <minishell/repl/repl.h>

// FIXME This file is kinda overloaded

static void
	_free_tokens(t_token *vec_tokens)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(vec_tokens))
		free(vec_tokens[i++].value);
	ft_vector_free(vec_tokens);
}

static void
	_print_lexer_error(t_lexer *lexer)
{
	size_t	i;

	if (lexer->status != LEXER_ERROR_UNCLOSED_QUOTE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: unexpected lexer error");
		return ;
	}
	ft_dprintf(STDERR_FILENO,
		"minishell: syntax error near unclosed quote\n%s\n",
		lexer->source);
	i = 0;
	while (i < lexer->position)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO,
		TERM_F_RED "^--- expected %c\n" TERM_RESET,
		lexer->error_info.expected_quote);
}

static void
	_print_parser_error(t_parser *parser, char *source)
{
	size_t	i;

	if (parser->error_info.got.type == TOKEN_EOF)
	{
		parser->error_info.got.value = "EOF";
		parser->error_info.got.position = ft_strlen(source);
	}
	ft_dprintf(STDERR_FILENO,
		"minishell: syntax error near unexpected token '%s'\n%s\n",
		parser->error_info.got.value,
		source);
	i = 0;
	while (i < parser->error_info.got.position)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO,
		TERM_F_RED "^--- expected %S\n" TERM_RESET,
		stringify_expected_tokens(parser->error_info.expected));
}

t_command_status
	parse_command(char *source, t_ast *result)
{
	t_token		*vec_tokens;
	t_lexer		lexer;
	t_parser	parser;

	vec_tokens = ft_vector_alloc_empty(sizeof(*vec_tokens));
	lexer = lexer_create(&vec_tokens);
	if (lexer_analyze(&lexer, source) != LEXER_OK)
	{
		_print_lexer_error(&lexer);
		_free_tokens(vec_tokens);
		return (COMMAND_LEXICAL_ERROR);
	}
	expand_tokens(vec_tokens);
	preparse(&vec_tokens);
	parser = parser_create(result);
	if (parser_parse(&parser, vec_tokens) != PARSER_OK)
	{
		_print_parser_error(&parser, source);
		_free_tokens(vec_tokens);
		return (COMMAND_SYNTAX_ERROR);
	}
	_free_tokens(vec_tokens);
	return (COMMAND_OK);
}
