/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_pipeline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:19:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 19:27:31 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/execution/execution_context.h>
#include <minishell/shell/signals.h>

#include <ft/vector/vector.h>
#include <ft/io/printf.h>

int
	shell_execute_pipeline(t_ast_pipeline *pipeline, t_execution_context *ctx)
{
	size_t	i;
	bool	error;
	int		status;

	ignore_signals();
	error = false;
	i = 0;
	while (i < ft_vector_get_size(pipeline->vec_commands) - 1)
	{
		pipe(ctx->current_pipe);
		if (!shell_launch_command(&pipeline->vec_commands[i], ctx, true))
			error = true;
		i++;
	}
	if (!shell_launch_command(&pipeline->vec_commands[i], ctx, false))
		error = true;
	dup2(shell_get_state()->stdin_backup, STDIN_FILENO);
	dup2(shell_get_state()->stdout_backup, STDOUT_FILENO);
	status = shell_await_children();
	if (error)
		status = 126;
	register_shell_signal_handlers();
	return (status);
}
