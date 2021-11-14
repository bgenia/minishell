/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:31:28 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/14 12:28:10 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/exec/exec.h>
#include <minishell/lexer/token.h>
#include <minishell/parser/ast.h>
#include <minishell/reade_line/read_line.h>
#include <unistd.h>
#include <libft/string/string.h>
#include <libft/vector/vector.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int run_command(t_ast *ast, char **env)
{
	pid_t	pidt;
	int		fd[2];

	pidt = fork();
	(void)env;
	if(pidt == 0)
	{
		dup2(fd[1], 1);
		execve(ft_strjoin("/bin/", ast->pipeline.vec_commands->vec_argv[0]), ast->pipeline.vec_commands->vec_argv, env);
		exit(0);
	}
	return (0);
}