/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:29:18 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 01:26:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/vector/vector.h>
#include <libft/system/env.h>
#include <libft/terminal/termdefs.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>
#include <minishell/parser/ast.h>
#include <minishell/parser/parser.h>
#include <minishell/parser/parser_utils.h>
#include <minishell/expander/expander.h>
#include <minishell/preparser/preparser.h>
#include <minishell/shell/shell_utils.h>

static void
	_free_tokens(t_token *vec_tokens)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(vec_tokens))
		free(vec_tokens[i++].value);
	ft_vector_free(vec_tokens);
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
		print_lexer_error(&lexer);
		_free_tokens(vec_tokens);
		return (COMMAND_LEXER_ERROR);
	}
	expand_tokens(vec_tokens);
	preparse(&vec_tokens);
	parser = parser_create(result);
	if (parser_parse(&parser, vec_tokens) != PARSER_OK)
	{
		print_parser_error(&parser, source);
		_free_tokens(vec_tokens);
		return (COMMAND_PARSER_ERROR);
	}
	_free_tokens(vec_tokens);
	expand_executables(result);
	return (COMMAND_OK);
}
