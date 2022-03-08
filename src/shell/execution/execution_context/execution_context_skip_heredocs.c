/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_context_skip_heredocs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:03:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 23:11:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/shell.h>
#include <minishell/parser/ast.h>
#include <minishell/shell/execution/execution_context.h>

#include <libft/vector/vector.h>

void
	execution_context_skip_heredocs(
		t_execution_context *ctx,
		t_ast_command *command
	)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(command->vec_redirections))
	{
		if (command->vec_redirections[i].type == REDIR_HEREDOC)
			ctx->heredoc_index++;
		i++;
	}
}
