/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_pipeline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:56:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 14:45:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/ast.h>
#include <minishell/lexer/token.h>

t_parser_status	parser_parse_pipeline(t_parser *parser, t_ast_pipeline *result)
{
	result->vec_commands = ft_vector_alloc_empty(sizeof(*result->vec_commands));
	parser_parse_command(parser, ft_vector_push_back(&result->vec_commands));
	if (parser->status != PARSER_OK)
		return (parser->status);
	while (parser_match(parser, TOKEN_PIPE))
	{
		parser_parse_command(
			parser,
			ft_vector_push_back(&result->vec_commands)
			);
		if (parser->status != PARSER_OK)
			return (parser->status);
	}
	return (parser->status);
}
