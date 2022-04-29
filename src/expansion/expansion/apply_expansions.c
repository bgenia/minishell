/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_expansions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:52:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 19:40:18 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/string/string.h>

#include <minishell/expansion/expansion.h>
#include <minishell/lexer/token.h>

void
	apply_expansions(t_token **token_vec_ptr)
{
	expand_variables(token_vec_ptr);
	split_simple_words(token_vec_ptr);
	merge_adjacent_words(token_vec_ptr);
	remove_whitespaces(token_vec_ptr);
}
