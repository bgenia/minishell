/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:51:28 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 02:53:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell_utils.h>

int
	*read_heredocs(t_ast *ast)
{
	size_t				i;
	size_t				j;
	t_ast_command		*command;
	t_ast_redirection	*redirection;
	int					*vec_fds;

	vec_fds = ft_vector_alloc_empty(sizeof(*vec_fds));
	i = 0;
	while (i < ft_vector_get_size(ast->pipeline.vec_commands))
	{
		command = &ast->pipeline.vec_commands[i];
		j = 0;
		while (j < ft_vector_get_size(command->vec_redirections))
		{
			redirection = &command->vec_redirections[j];
			if (redirection->type != REDIR_HEREDOC)
				continue ;
			*(int *)ft_vector_push_back(&vec_fds) = \
				read_heredoc(redirection->file);
			j++;
		}
		i++;
	}
	return (vec_fds);
}
