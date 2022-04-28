/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/lexer/lexer.h>
#include <minishell/shell/shell_colors.h>
#include <minishell/shell/shell_utils.h>

#include <ft/io/printf.h>

void
	print_lexer_error(t_lexer *lexer)
{
	if (lexer->status != LEXER_ERROR_UNCLOSED_QUOTE)
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: unexpected lexer error\n%s",
			shell_colorize(TERM_F_RED), shell_colorize(TERM_RESET));
		return ;
	}
	ft_dprintf(STDERR_FILENO, "%sminishell: syntax error near unclosed quote\n>"
		"%s %s\n  ", shell_colorize(TERM_F_RED), shell_colorize(TERM_RESET),
		lexer->source);
	print_many(STDERR_FILENO, ' ', lexer->position);
	ft_dprintf(STDERR_FILENO, "%s^--- expected %c\n%s",
		shell_colorize(TERM_F_RED), lexer->error_info.expected_quote,
		shell_colorize(TERM_RESET));
}
