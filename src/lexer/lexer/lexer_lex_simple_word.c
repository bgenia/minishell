/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex_simple_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:36:03 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/31 10:58:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>
#include <minishell/lexer/lexer_utils.h>

void	lexer_lex_simple_word(t_lexer *lexer)
{
	char	current;
	size_t	position;

	position = lexer->position;
	current = lexer_skip(lexer, 1);
	while (!is_word_delimiter(current))
		current = lexer_skip(lexer, 1);
	lexer_add_token(lexer, TOKEN_WORD, position, lexer->position - position);
}
