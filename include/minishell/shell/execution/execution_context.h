/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_context.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:06:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 21:08:53 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_CONTEXT_H
# define EXECUTION_CONTEXT_H

# include <minishell/parser/ast.h>

typedef struct s_execution_context
{
	t_ast	*ast;
	int		*vec_heredoc_fds;
	int		heredoc_index;
	int		current_pipe[2];
}	t_execution_context;

void
execution_context_init(t_execution_context *ctx, t_ast *ast);

int
execution_context_get_next_heredoc(t_execution_context *ctx);

void
execution_context_skip_heredocs(
	t_execution_context *ctx,
	t_ast_command *command
	);

#endif
