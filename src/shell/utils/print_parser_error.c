/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:42:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 07:06:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/parser/parser.h>
#include <minishell/parser/parser_utils.h>

#include <libft/io/printf.h>
#include <libft/terminal/termdefs.h>
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
	ft_dprintf(STDERR_FILENO, TERM_F_RED
		"minishell: syntax error near unexpected token '%s'\n> " TERM_RESET
		"%s\n  ", parser->error_info.got.value, source);
	i = 0;
	while (i < parser->error_info.got.position)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO,
		TERM_F_RED "^--- expected %S\n" TERM_RESET,
		stringify_expected_tokens(parser->error_info.expected));
}
