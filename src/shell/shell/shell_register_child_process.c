/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_register_child_process.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:10:13 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 01:20:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include <minishell/shell/shell.h>

#include <libft/vector/vector.h>

void
	shell_register_child_process(pid_t pid)
{
	t_shell_state	*shell_state;

	shell_state = shell_get_state();
	if (!shell_state->_vec_children)
	{
		shell_state->_vec_children = \
			ft_vector_alloc_empty(sizeof(shell_state->_vec_children));
	}
	*(pid_t *)ft_vector_push_back(&shell_state->_vec_children) = pid;
}
