/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:01:00 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/10 21:22:20 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

t_lexer	lexer_create(t_token **vec_tokens)
{
	return ((t_lexer){
		.heredoc_mode = false,
		.position = 0,
		.source = NULL,
		.vec_tokens = vec_tokens
	});
}
