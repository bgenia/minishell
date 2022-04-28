/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex_whitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:36:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/ctype.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

void
	lexer_lex_whitespace(t_lexer *lexer)
{
	char	current;
	size_t	position;

	position = lexer->position;
	current = lexer_skip(lexer, 1);
	while (ft_isspace(current))
		current = lexer_skip(lexer, 1);
	lexer_add_token(lexer, TOKEN_SPACE, position, lexer->position - position);
}
