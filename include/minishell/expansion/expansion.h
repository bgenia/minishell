/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:05:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 19:47:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <stddef.h>

# include <minishell/lexer/token.h>
# include <minishell/parser/ast.h>

void
apply_expansions(t_token **token_vec_ptr);

void
expand_variables(t_token **token_vec_ptr);
void
split_simple_words(t_token **token_vec_ptr);
void
merge_adjacent_words(t_token **token_vec_ptr);
void
remove_whitespaces(t_token **token_vec_ptr);

#endif
