/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:09:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 12:47:53 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdbool.h>

# include <minishell/parser/ast.h>
# include <minishell/shell/execution/execution_context.h>

typedef enum e_shell_result
{
	SHELL_OK,
	SHELL_ERROR
}	t_shell_result;

t_shell_result
shell_execute_line(char *command);

void
shell_execute_ast(t_ast *ast);

int
shell_execute_pipeline(t_ast_pipeline *pipeline, t_execution_context *ctx);

int
shell_execute_builtin(t_ast_command *command, t_execution_context *ctx);

bool
shell_launch_command(
	t_ast_command *command,
	t_execution_context *ctx,
	bool has_output_pipe
	);

void
shell_execute_command(t_ast_command *command);

#endif
