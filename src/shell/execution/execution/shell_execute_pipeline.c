/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_pipeline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:19:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 23:11:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/execution/execution_context.h>

#include <libft/vector/vector.h>

int
	shell_execute_pipeline(t_ast_pipeline *pipeline, t_execution_context *ctx)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(pipeline->vec_commands) - 1)
	{
		pipe(ctx->current_pipe);
		shell_launch_command(&pipeline->vec_commands[i], ctx, true, i > 0);
		i++;
	}
	shell_launch_command(&pipeline->vec_commands[i], ctx, false, i > 0);
	dup2(shell_get_state()->stdin_backup, STDIN_FILENO);
	dup2(shell_get_state()->stdout_backup, STDOUT_FILENO);
	return (shell_await_children());
}
