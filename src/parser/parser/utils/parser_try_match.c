/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_try_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:32:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/11 06:26:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>
#include <minishell/lexer/token.h>

bool
	parser_try_match(t_parser *parser, int offset, t_token_type type)
{
	if (parser_peek(parser, offset).type & type)
		return (true);
	parser->expected_token |= type;
	return (false);
}
