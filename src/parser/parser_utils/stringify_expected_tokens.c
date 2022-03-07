/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringify_expected_tokens.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:26:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 16:03:03 by bgenia           ###   ########.fr       */
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

char
	*stringify_expected_tokens(t_token_type expected)
{
	char	*result;
	int		i;

	result = NULL;
	i = TOKEN_PIPE;
	while (i <= TOKEN_EOF)
	{
		if (!result && expected & i)
			result = ft_strdup(g_token_types[i]);
		else if (result && expected & i)
			result = ft_aformat("%S or %s", result, g_token_types[i]);
		i *= 2;
	}
	return (result);
}
