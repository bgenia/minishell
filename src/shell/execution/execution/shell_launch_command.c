/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_launch_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:59:15 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 22:00:46 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/execution/execution_context.h>

void
	shell_launch_command(
		t_ast_command *command,
		t_execution_context *ctx,
		bool has_output_pipe,
		bool has_input_pipe
	)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (has_output_pipe)
		{
			close(ctx->current_pipe[0]);
			dup2(ctx->current_pipe[1], STDOUT_FILENO);
		}
		shell_apply_redirections(command, ctx);
		shell_execute_command(command);
	}
	shell_register_child_process(pid);
	execution_context_skip_heredocs(ctx, command);
	if (has_output_pipe)
	{
		dup2(ctx->current_pipe[0], STDIN_FILENO);
		close(ctx->current_pipe[0]);
		close(ctx->current_pipe[1]);
	}
	if (has_input_pipe)
	{
		close(STDIN_FILENO);
	}
}
