/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_launch_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:59:15 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 10:59:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/execution/execution_context.h>
#include <minishell/shell/execution/redirections.h>
#include <minishell/shell/shell_colors.h>

#include <libft/io/printf.h>

static void
	_apply_output_pipe(t_execution_context *ctx)
{
	close(ctx->current_pipe[0]);
	dup2(ctx->current_pipe[1], STDOUT_FILENO);
}

static void
	_use_output_pipe(t_execution_context *ctx)
{
	dup2(ctx->current_pipe[0], STDIN_FILENO);
	close(ctx->current_pipe[0]);
	close(ctx->current_pipe[1]);
}

bool
	shell_launch_command(
		t_ast_command *command,
		t_execution_context *ctx,
		bool has_output_pipe,
		bool has_input_pipe
	)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(STDERR_FILENO, _TERM_F_RED "minishell: %s: unable to fork "
			"process\n" _TERM_RESET, command->vec_argv[0]);
		return (false);
	}
	if (pid == 0)
	{
		if (has_output_pipe)
			_apply_output_pipe(ctx);
		shell_apply_redirections(command, ctx);
		shell_execute_command(command);
	}
	shell_register_child_process(pid);
	execution_context_skip_heredocs(ctx, command);
	if (has_output_pipe)
		_use_output_pipe(ctx);
	if (has_input_pipe)
		close(STDIN_FILENO);
	return (true);
}
