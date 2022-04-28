/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:32:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/ast.h>
#include <minishell/lexer/token.h>

t_parser_status
	pasrer_parse_redirection(t_parser *parser, t_ast_redirection *result)
{
	t_token	redirection;
	char	*source;

	if (!parser_consume(parser, TOKEN_RHD | TOKEN_RL | TOKEN_RR | TOKEN_RRA))
		return (parser->status);
	redirection = parser_peek(parser, -1);
	if (parser_parse_word(parser, &source) != PARSER_OK)
		return (parser->status);
	result->file = source;
	result->fd = redirection.fd;
	if (redirection.type == TOKEN_RHD)
		result->type = REDIR_HEREDOC;
	else if (redirection.type == TOKEN_RRA)
		result->type = REDIR_APPEND;
	else if (redirection.type == TOKEN_RL)
		result->type = REDIR_INPUT;
	else
		result->type = REDIR_OUTPUT;
	return (parser->status);
}
