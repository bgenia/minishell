/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:31:43 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/04 20:32:11 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory/memory.h>
#include <libft/string/string.h>
#include <minishell/reade_line/read_line.h>
#include <minishell/lexer/lexer.h>
#include <minishell/lexer/lexer_utils.h>
#include <minishell/lexer/token.h>
#include <minishell/heredoc/heredoc.h>

t_global_v *g_val;

int	main(int argc, char const *argv[], char const *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	t_lexer *lexer;

	lexer = ft_calloc(sizeof(t_lexer), 1);
	g_val = ft_calloc(sizeof(t_global_v), 1);
	if (!g_val)
		return (1);
	while (1)
	{
		g_val->str = read_line();
		if (!ft_strcmp(g_val->str, "exit"))
			break;
		lexer_analyze(lexer, g_val->str);
		
		// продолжение следует
	}
	return (0);
}
