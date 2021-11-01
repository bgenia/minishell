/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:07:49 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/31 19:15:17 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPARSER_H
# define PREPARSER_H

# include <minishell/lexer/token.h>

void
preparse(t_token **token_vec_ptr);

void
split_simple_words(t_token **token_vec_ptr);

void
merge_adjacent_words(t_token **token_vec_ptr);

void
remove_whitespaces(t_token **token_vec_ptr);

#endif
