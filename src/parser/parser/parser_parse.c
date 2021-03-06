/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:49:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

#include <minishell/parser/parser.h>
#include <minishell/lexer/token.h>

t_parser_status
	parser_parse(t_parser *parser, t_token *vec_tokens)
{
	parser->vec_tokens = vec_tokens;
	parser->position = 0;
	parser->length = ft_vector_get_size(vec_tokens);
	return (parser_parse_pipeline(parser, &parser->ast->pipeline));
}
