/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:46:30 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:16:21 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/vector/vector.h>

#include <minishell/parser/ast.h>

void
	ast_destroy(t_ast *ast)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_vector_get_size(ast->pipeline.vec_commands))
	{
		j = 0;
		while (j < ft_vector_get_size(ast->pipeline.vec_commands[i].vec_argv))
		{
			free(ast->pipeline.vec_commands[i].vec_argv[j]);
			j++;
		}
		j = 0;
		while (j < ft_vector_get_size(
				ast->pipeline.vec_commands[i].vec_redirections))
		{
			free(ast->pipeline.vec_commands[i].vec_redirections[j].file);
			j++;
		}
		ft_vector_free(ast->pipeline.vec_commands[i].vec_argv);
		ft_vector_free(ast->pipeline.vec_commands[i].vec_redirections);
		i++;
	}
	ft_vector_free(ast->pipeline.vec_commands);
}
