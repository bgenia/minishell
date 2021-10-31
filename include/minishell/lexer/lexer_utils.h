/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:50:42 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/31 10:39:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

# include <stdbool.h>

bool
is_quote(char c);

bool
is_word_delimiter(char c);

bool
is_redirection_char(char c);

#endif
