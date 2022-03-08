/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_builtin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 22:48:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/execution/execution_context.h>
#include <minishell/builtins/builtin_utils.h>

int
	shell_execute_builtin(
		t_ast_command *command,
		t_execution_context *ctx
	)
{
	int	status;

	shell_apply_redirections(command, ctx);
	status = exec_builtin(command->vec_argv[0], command->vec_argv);
	shell_close_redirections(command);
	return (status);
}
