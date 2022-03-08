/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:42:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 23:43:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/parser/parser.h>

#include <libft/io/printf.h>
#include <libft/terminal/termdefs.h>

void
	print_parser_error(t_parser *parser, char *source)
{
	size_t	i;

	ft_dprintf(STDERR_FILENO,
		"minishell: syntax error near unexpected token %s\n%s\n",
		parser->error_info.got.value,
		source);
	i = 0;
	while (i < parser->error_info.got.position - 1)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO,
		TERM_F_RED "^--- here\n" TERM_RESET "expected %S\n",
		stringify_expected_tokens(parser->error_info.expected));
}
