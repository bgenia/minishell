/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 20:21:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/lexer/lexer.h>
#include <minishell/shell/shell_colors.h>
#include <minishell/shell/shell_utils.h>

#include <ft/io/printf.h>
#include <ft/process/env.h>

void
	print_lexer_error(t_lexer *lexer)
{
	if (lexer->status != LEXER_ERROR_UNCLOSED_QUOTE)
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: lexical error\n%s",
			shell_colorize(TERM_F_RED), shell_colorize(TERM_RESET));
		return ;
	}
	ft_dprintf(STDERR_FILENO, "%sminishell: syntax error near unclosed quote"
		"%s\n", shell_colorize(TERM_F_RED), shell_colorize(TERM_RESET));
	if (!ft_getenv("MSH_USE_DETAILED_ERRORS"))
		return ;
	ft_dprintf(STDERR_FILENO, "%s>%s %s\n  ", shell_colorize(TERM_F_RED),
		shell_colorize(TERM_RESET), lexer->source);
	print_many(STDERR_FILENO, ' ', lexer->position);
	ft_dprintf(STDERR_FILENO, "%s^--- expected %c\n%s",
		shell_colorize(TERM_F_RED), lexer->error_info.expected_quote,
		shell_colorize(TERM_RESET));
}
