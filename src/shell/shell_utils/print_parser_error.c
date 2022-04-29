/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:42:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 20:21:24 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/parser_utils.h>
#include <minishell/shell/shell_colors.h>
#include <minishell/shell/shell_utils.h>

#include <ft/io/printf.h>
#include <ft/string/string.h>
#include <ft/math.h>
#include <ft/process/env.h>

void
	print_parser_error(t_parser *parser, char *source)
{
	if (parser->error_info.got.type == TOKEN_EOF)
	{
		parser->error_info.got.value = "EOF";
		parser->error_info.got.position = ft_strlen(source);
	}
	ft_dprintf(STDERR_FILENO, "%sminishell: syntax error near unexpected token "
		"'%s'%s\n", shell_colorize(TERM_F_RED), parser->error_info.got.value,
		shell_colorize(TERM_RESET));
	if (!ft_getenv("MSH_USE_DETAILED_ERRORS"))
		return ;
	ft_dprintf(STDERR_FILENO, "%s> %s%s\n%s  ", shell_colorize(TERM_F_RED),
		shell_colorize(TERM_RESET), source, shell_colorize(TERM_F_RED));
	print_many(STDERR_FILENO, ' ', parser->error_info.got.position);
	print_many(STDERR_FILENO, '^', ft_maxu(parser->error_info.got.length, 1));
	ft_dprintf(STDERR_FILENO, "--- expected %S\n%s",
		stringify_expected_tokens(parser->error_info.expected),
		shell_colorize(TERM_RESET));
}
