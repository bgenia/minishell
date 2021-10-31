/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_raise_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:32 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/31 09:42:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/lexer/lexer.h>

t_lexer_status	lexer_raise_error(t_lexer *lexer, t_lexer_error error)
{
	lexer->status = LEXER_ERROR;
	lexer->error = error;
	return (lexer->status);
}
