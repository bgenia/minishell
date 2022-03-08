/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:36:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:12:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ctype.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

void	lexer_lex_pipe(t_lexer *lexer)
{
	lexer_skip(lexer, 1);
	lexer_add_token(lexer, TOKEN_PIPE, lexer->position - 1, 1);
}
