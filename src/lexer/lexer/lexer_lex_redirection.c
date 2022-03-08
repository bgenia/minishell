/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:36:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:11:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ctype.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

void	lexer_lex_redirection(t_lexer *lexer)
{
	char			current;
	size_t			position;
	t_token_type	type;

	position = lexer->position;
	current = lexer_peek(lexer, 0);
	if (ft_isdigit(current))
		current = lexer_skip(lexer, 1);
	if (lexer_peek(lexer, 1) == current)
	{
		current = lexer_skip(lexer, 1);
		if (current == '<')
			type = TOKEN_RHD;
		else
			type = TOKEN_RRA;
	}
	else if (current == '<')
		type = TOKEN_RL;
	else
		type = TOKEN_RR;
	lexer_skip(lexer, 1);
	lexer_add_token(lexer, type, position, lexer->position - position);
}
