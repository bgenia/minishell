/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_close_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:43:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 22:47:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/execution/execution_context.h>

#include <libft/vector/vector.h>

void
	shell_close_redirections(t_ast_command *command)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(command->vec_redirections))
	{
		close(command->vec_redirections[i].fd);
		i++;
	}
}
