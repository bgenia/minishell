/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:25:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 15:33:16 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>

t_token	parser_peek(t_parser *parser, int offset)
{
	if (parser->position + offset < parser->length)
		return (parser->vec_tokens[parser->position + offset]);
	return ((t_token){.type = TOKEN_EOF});
}
