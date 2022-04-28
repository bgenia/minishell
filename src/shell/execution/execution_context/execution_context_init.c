/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_context_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:47:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/execution/execution_context.h>

#include <ft/vector/vector.h>

void
	execution_context_init(t_execution_context *ctx, t_ast *ast)
{
	ctx->ast = ast;
	ctx->vec_heredoc_fds = ft_vector_alloc_empty(sizeof(*ctx->vec_heredoc_fds));
	ctx->heredoc_index = 0;
}
