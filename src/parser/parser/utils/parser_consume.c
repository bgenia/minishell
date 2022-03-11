/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_consume.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:35:08 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/11 06:20:13 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>
#include <minishell/lexer/token.h>

bool
	parser_consume(t_parser *parser, t_token_type type)
{
	if (!parser_match(parser, type))
	{
		parser_set_status(parser, PARSER_ERROR_BAD_SYNTAX);
		parser->error_info = (t_parser_error_info){
			.expected = parser->expected_token,
			.got = parser_peek(parser, 0)
		};
		return (false);
	}
	parser->expected_token = 0;
	return (true);
}
