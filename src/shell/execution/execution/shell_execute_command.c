/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:56:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 01:36:05 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/builtins/builtin_utils.h>

#include <libft/system/env.h>
#include <libft/io/printf.h>

void
	shell_execute_command(t_ast_command *command)
{
	if (is_builtin(command->vec_argv[0]))
		exit(exec_builtin(command->vec_argv[0], command->vec_argv));
	if (access(command->vec_argv[0], F_OK))
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: no such file or directory\n",
			command->vec_argv[0]);
		exit(127);
	}
	if (access(command->vec_argv[0], X_OK))
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: permission denied\n",
			command->vec_argv[0]);
		exit(126);
	}
	execve(command->vec_argv[0], command->vec_argv, environ);
	ft_dprintf(STDERR_FILENO,
		"minishell: %s: execution failed\n",
		command->vec_argv[0]);
	exit(-1);
}
