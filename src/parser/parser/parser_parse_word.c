/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:42:48 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:16:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>
#include <libft/string/string.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/ast.h>
#include <minishell/lexer/token.h>

t_parser_status
	parser_parse_word(t_parser *parser, char **result)
{
	t_token	word;

	word = parser_peek(parser, 0);
	parser_consume(parser, TOKEN_WORD);
	if (parser->status != PARSER_OK)
		return (parser->status);
	*result = ft_strdup(word.value);
	return (parser->status);
}
