/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:37:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 16:06:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <minishell/parser/ast.h>

#include <libft/string/string.h>

#include <readline/readline.h>

// TODO Make an enum or smth
#define REPL_OK		0
#define REPL_STOP	1
#define REPL_SKIP	2

int
	repl_eval(char *command)
{
	t_ast	*ast;

	if (!command)
	{
		return (REPL_STOP);
	}
	if (ft_strisempty(command))
	{
		rl_on_new_line();
		return (REPL_SKIP);
	}
	if (parse_co)
	return (REPL_OK);
}
