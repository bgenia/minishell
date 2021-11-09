/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_set_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:32 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/09 20:42:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/lexer/lexer.h>

t_lexer_status	lexer_set_status(t_lexer *lexer, t_lexer_status status)
{
	lexer->status = status;
	return (lexer->status);
}
