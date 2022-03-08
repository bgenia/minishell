/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_executables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:18:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:19:10 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/vector/vector.h>

#include <minishell/parser/ast.h>
#include <minishell/expander/expander.h>
#include <minishell/builtins/builtin_utils.h>

void
	expand_executables(t_ast *ast)
{
	size_t	i;
	char	**program;
	char	*executable;

	i = 0;
	while (i < ft_vector_get_size(ast->pipeline.vec_commands))
	{
		program = &ast->pipeline.vec_commands[i++].vec_argv[0];
		if (is_builtin(*program))
			continue ;
		executable = get_executable(*program);
		if (executable)
		{
			free(*program);
			*program = executable;
		}
	}
}
