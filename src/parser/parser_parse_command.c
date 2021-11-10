/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:11:16 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/10 21:51:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/ast.h>
#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer_utils.h>

t_parser_status	parser_parse_command(
	t_parser *parser,
	t_ast_command *result
)
{
	result->vec_argv = ft_vector_alloc_empty(sizeof(*result->vec_argv));
	result->vec_redirections
		= ft_vector_alloc_empty(sizeof(*result->vec_redirections));
	if (parser_peek(parser, 0).type == TOKEN_WORD)
		parser_parse_word(parser, ft_vector_push_back(&result->vec_argv));
	else
		pasrer_parse_redirection(
			parser, ft_vector_push_back(&result->vec_redirections));
	if (parser->status != PARSER_OK)
		return (parser->status);
	while (parser_peek(parser, 0).type == TOKEN_WORD
		|| is_redirection(parser_peek(parser, 0).type))
	{
		if (parser_peek(parser, 0).type == TOKEN_WORD)
			parser_parse_word(parser, ft_vector_push_back(&result->vec_argv));
		else
			pasrer_parse_redirection(
				parser, ft_vector_push_back(&result->vec_redirections));
	}
	return (parser->status);
}
