/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:11:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/11 06:29:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/ast.h>
#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer_utils.h>

t_parser_status
	parser_parse_command(t_parser *parser, t_ast_command *result)
{
	result->vec_argv = ft_vector_alloc_empty(sizeof(*result->vec_argv));
	result->vec_redirections
		= ft_vector_alloc_empty(sizeof(*result->vec_redirections));
	if (parser_try_match(parser, 0, TOKEN_WORD))
		parser_parse_word(parser, ft_vector_push_back(&result->vec_argv));
	else
		pasrer_parse_redirection(
			parser, ft_vector_push_back(&result->vec_redirections));
	if (parser->status != PARSER_OK)
		return (parser->status);
	while (parser_try_match(parser, 0, TOKEN_WORD | TOKEN_REDIR))
	{
		if (parser_try_match(parser, 0, TOKEN_WORD))
			parser_parse_word(parser, ft_vector_push_back(&result->vec_argv));
		else
			pasrer_parse_redirection(
				parser, ft_vector_push_back(&result->vec_redirections));
	}
	return (parser->status);
}
