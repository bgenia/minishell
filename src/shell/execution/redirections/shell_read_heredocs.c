/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:51:28 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 06:34:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/execution/execution_context.h>
#include <minishell/shell/execution/redirections.h>

void
	shell_read_heredocs(t_ast *ast, t_execution_context *ctx)
{
	size_t				i;
	size_t				j;
	t_ast_command		*command;
	t_ast_redirection	*redirection;

	i = 0;
	while (i < ft_vector_get_size(ast->pipeline.vec_commands))
	{
		command = &ast->pipeline.vec_commands[i++];
		j = 0;
		while (j < ft_vector_get_size(command->vec_redirections))
		{
			redirection = &command->vec_redirections[j++];
			if (redirection->type != REDIR_HEREDOC)
				continue ;
			*(int *)ft_vector_push_back(&ctx->vec_heredoc_fds) = \
				shell_read_heredoc(redirection->file);
		}
	}
}
