/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:42:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/11 07:11:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/parser_utils.h>
#include <minishell/shell/shell_colors.h>

#include <libft/io/printf.h>
#include <libft/string/string.h>

void
	print_parser_error(t_parser *parser, char *source)
{
	size_t	i;

	if (parser->error_info.got.type == TOKEN_EOF)
	{
		parser->error_info.got.value = "EOF";
		parser->error_info.got.position = ft_strlen(source);
	}
	ft_dprintf(STDERR_FILENO, _TERM_F_RED
		"minishell: syntax error near unexpected token '%s'\n> " _TERM_RESET
		"%s\n  " _TERM_F_RED, parser->error_info.got.value, source);
	i = 0;
	while (i < parser->error_info.got.position)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO, "^");
	i = 1;
	while (i < parser->error_info.got.length)
	{
		ft_dprintf(STDERR_FILENO, "^");
		i++;
	}
	ft_dprintf(STDERR_FILENO, "--- expected %S\n" _TERM_RESET,
		stringify_expected_tokens(parser->error_info.expected));
}
