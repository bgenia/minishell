/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:18:39 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:28:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_UTILS_H
# define SHELL_UTILS_H

# include <minishell/parser/ast.h>
# include <minishell/parser/parser.h>
# include <minishell/lexer/lexer.h>
# include <minishell/shell/execution/execution_context.h>

typedef enum e_command_status
{
	COMMAND_OK,
	COMMAND_LEXER_ERROR,
	COMMAND_PARSER_ERROR
}	t_command_status;

void
print_lexer_error(t_lexer *lexer);

void
print_parser_error(t_parser *parser, char *source);

t_command_status
parse_command(char *source, t_ast *result);

int
read_heredoc(char *name);

#endif
