/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word_delimiter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:52:53 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:18:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <libft/ctype.h>

#include <minishell/lexer/lexer_utils.h>

bool
	is_word_delimiter(char c)
{
	return (c == '\0' || c == '>' || c == '<' || c == '|'
		|| is_quote(c) || ft_isspace(c));
}
