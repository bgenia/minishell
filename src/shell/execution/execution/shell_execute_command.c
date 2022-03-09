/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:56:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 07:34:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/builtins/builtin_utils.h>
#include <minishell/shell/shell_colors.h>

#include <libft/system/env.h>
#include <libft/io/printf.h>
#include <libft/string/string.h>

static void
	_display_missing_file_error(t_ast_command *command)
{
	if (ft_strchr(command->vec_argv[0], '/'))
	{
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: no such file or directory\n" _TERM_RESET,
			command->vec_argv[0]);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: command not found\n" _TERM_RESET,
			command->vec_argv[0]);
	}
}

static void
	_display_missing_permissions_error(t_ast_command *command)
{
	ft_dprintf(STDERR_FILENO, _TERM_F_RED
		"minishell: %s: permission denied\n" _TERM_RESET,
		command->vec_argv[0]);
}

static void
	_display_unknown_execution_error(t_ast_command *command)
{
	ft_dprintf(STDERR_FILENO, _TERM_F_RED
		"minishell: %s: execution failed\n" _TERM_RESET,
		command->vec_argv[0]);
}

void
	shell_execute_command(t_ast_command *command)
{
	if (is_builtin(command->vec_argv[0]))
		exit(exec_builtin(command->vec_argv[0], command->vec_argv));
	if (access(command->vec_argv[0], F_OK))
	{
		_display_missing_file_error(command);
		exit(127);
	}
	if (access(command->vec_argv[0], X_OK))
	{
		_display_missing_permissions_error(command);
		exit(126);
	}
	execve(command->vec_argv[0], command->vec_argv, environ);
	_display_unknown_execution_error(command);
	exit(-1);
}
