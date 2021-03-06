/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:32:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/11 08:36:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>
#include <minishell/lexer/token.h>

bool
	parser_match(t_parser *parser, t_token_type type)
{
	if (parser_peek(parser, 0).type & type)
	{
		parser->expected_token = 0;
		parser_skip(parser, 1);
		return (true);
	}
	parser->expected_token |= type;
	return (false);
}
