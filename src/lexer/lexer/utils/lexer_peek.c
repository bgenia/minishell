/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:30:28 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:17:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/lexer/lexer.h>

char
	lexer_peek(t_lexer *lexer, int offset)
{
	if (lexer->position + offset < lexer->length)
		return (lexer->source[lexer->position + offset]);
	return ('\0');
}
