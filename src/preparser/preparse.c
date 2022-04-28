/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:16:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

#include <minishell/lexer/token.h>
#include <minishell/preparser/preparser.h>

void
	preparse(t_token **token_vec_ptr)
{
	split_simple_words(token_vec_ptr);
	merge_adjacent_words(token_vec_ptr);
	remove_whitespaces(token_vec_ptr);
}
