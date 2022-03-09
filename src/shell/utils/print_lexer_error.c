/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 07:34:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/lexer/lexer.h>
#include <minishell/shell/shell_colors.h>

#include <libft/io/printf.h>

void
	print_lexer_error(t_lexer *lexer)
{
	size_t	i;

	if (lexer->status != LEXER_ERROR_UNCLOSED_QUOTE)
	{
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: unexpected lexer error\n" _TERM_RESET);
		return ;
	}
	ft_dprintf(STDERR_FILENO, _TERM_F_RED
		"minishell: syntax error near unclosed quote\n> " _TERM_RESET "%s\n  ",
		lexer->source);
	i = 0;
	while (i < lexer->position)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO,
		_TERM_F_RED "^--- expected %c\n" _TERM_RESET,
		lexer->error_info.expected_quote);
}
