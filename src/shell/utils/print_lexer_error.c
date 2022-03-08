/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 01:35:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/lexer/lexer.h>

#include <libft/io/printf.h>
#include <libft/terminal/termdefs.h>

void
	print_lexer_error(t_lexer *lexer)
{
	size_t	i;

	if (lexer->status != LEXER_ERROR_UNCLOSED_QUOTE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: unexpected lexer error\n");
		return ;
	}
	ft_dprintf(STDERR_FILENO,
		"minishell: syntax error near unclosed quote\n%s\n",
		lexer->source);
	i = 0;
	while (i < lexer->position)
	{
		ft_dprintf(STDERR_FILENO, " ");
		i++;
	}
	ft_dprintf(STDERR_FILENO,
		TERM_F_RED "^--- expected %c\n" TERM_RESET,
		lexer->error_info.expected_quote);
}
