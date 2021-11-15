/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_executables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:18:52 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 19:22:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/vector/vector.h>

#include <minishell/parser/ast.h>
#include <minishell/expander/expander.h>

void	expand_executables(t_ast *ast)
{
	size_t	i;
	char	*executable;

	i = 0;
	while (i < ft_vector_get_size(ast->pipeline.vec_commands))
	{
		executable = get_executable(ast->pipeline.vec_commands[i].vec_argv[0]);
		if (executable)
		{
			free(ast->pipeline.vec_commands[i].vec_argv[0]);
			ast->pipeline.vec_commands[i].vec_argv[0] = executable;
		}
		i++;
	}
}
