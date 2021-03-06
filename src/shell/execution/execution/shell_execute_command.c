/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:56:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/05 17:38:20 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/builtins/builtin_utils.h>
#include <minishell/shell/shell_colors.h>
#include <minishell/shell/shell_utils.h>

#include <ft/process/env.h>
#include <ft/io/printf.h>
#include <ft/string/string.h>

static void
	_display_missing_file_error(t_ast_command *command)
{
	if (ft_strchr(command->vec_argv[0], '/'))
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: %s: no such file or directory\n"
			"%s", shell_colorize(TERM_F_RED), command->vec_argv[0],
			shell_colorize(TERM_RESET));
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: %s: command not found\n%s",
			shell_colorize(TERM_F_RED), command->vec_argv[0],
			shell_colorize(TERM_RESET));
	}
}

static void
	_display_missing_permissions_error(t_ast_command *command)
{
	ft_dprintf(STDERR_FILENO, "%sminishell: %s: permission denied\n%s",
		shell_colorize(TERM_F_RED), command->vec_argv[0],
		shell_colorize(TERM_RESET));
}

static void
	_display_unknown_execution_error(t_ast_command *command)
{
	ft_dprintf(STDERR_FILENO, "%sminishell: %s: execution failed\n%s",
		shell_colorize(TERM_F_RED), command->vec_argv[0],
		shell_colorize(TERM_RESET));
}

static int
	_execute_implicit(void)
{
	char	**argv;

	if (ft_getenv("MSH_USE_IMPLICIT_CAT"))
	{
		argv = (char *[]){"cat", NULL};
		return (execve("/usr/bin/cat", argv, environ));
	}
	argv = (char *[]){NULL};
	return (exec_builtin(NULL, argv));
}

void
	shell_execute_command(t_ast_command *command)
{
	char	*executable;

	if (!command->vec_argv[0])
		exit(_execute_implicit());
	if (is_builtin(command->vec_argv[0]))
		exit(exec_builtin(command->vec_argv[0], command->vec_argv));
	executable = get_path_executable(command->vec_argv[0]);
	if (!executable || access(executable, F_OK))
	{
		_display_missing_file_error(command);
		exit(127);
	}
	if (access(executable, X_OK))
	{
		_display_missing_permissions_error(command);
		exit(126);
	}
	execve(executable, command->vec_argv, environ);
	_display_unknown_execution_error(command);
	exit(-1);
}
