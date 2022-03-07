/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parser_error_message.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:26:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 15:31:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string/string.h>
#include <libft/string/format.h>

#include <minishell/parser/parser_utils.h>
#include <minishell/lexer/token.h>

const static char	*g_token_types[] = {
[TOKEN_RL] = "<",
[TOKEN_RR] = ">",
[TOKEN_RHD] = "<<",
[TOKEN_RRA] = ">>",
[TOKEN_PIPE] = "|",
[TOKEN_SPACE] = "a whitespace",
[TOKEN_WORD] = "a word",
[TOKEN_EOF] = "an EOF"
};

char	*create_parser_error_message(t_parser_error_info *error)
{
	char	*expected;
	char	*got;
	int		i;

	expected = NULL;
	i = TOKEN_PIPE;
	while (i <= TOKEN_EOF)
	{
		if (!expected && error->expected & i)
			expected = ft_strdup(g_token_types[i]);
		else if (expected && error->expected & i)
			expected = ft_aformat("%S or %s", expected, g_token_types[i]);
		i *= 2;
	}
	if (error->got.value)
		got = ft_aformat("'%s'", error->got.value);
	else
		got = ft_strdup(g_token_types[error->got.type]);
	return (ft_aformat(
			"Syntax error! Expected %S, but got %S",
			expected,
			got
		));
}
