/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:32:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 06:30:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/execution/execution_context.h>
#include <minishell/shell/execution/redirections.h>
#include <minishell/shell/shell_utils.h>
#include <minishell/builtins/builtin_utils.h>

#include <libft/vector/vector.h>
#include <libft/system/env.h>
#include <libft/string/format.h>

static bool
	_is_only_command(t_execution_context *ctx)
{
	return (ft_vector_get_size(ctx->ast->pipeline.vec_commands) == 1);
}

void
	shell_execute_ast(t_ast *ast)
{
	t_execution_context	ctx;
	int					status;

	execution_context_init(&ctx, ast);
	shell_get_state()->state = SHELL_READING_HEREDOC;
	shell_read_heredocs(ast, &ctx);
	shell_get_state()->state = SHELL_RUNNING;
	if (_is_only_command(&ctx)
		&& is_builtin_command(&ast->pipeline.vec_commands[0]))
		status = shell_execute_builtin(&ast->pipeline.vec_commands[0], &ctx);
	else
		status = shell_execute_pipeline(&ast->pipeline, &ctx);
	shell_set_last_status(status);
	shell_clear_heredocs(&ctx);
	shell_get_state()->state = SHELL_WAITING;
}
