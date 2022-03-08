/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:46:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 01:07:24 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/shell/shell.h>

t_shell_state
	*shell_get_state(void)
{
	static t_shell_state	shell_state = (t_shell_state){
		.is_running = false,
		.stdin_backup = -1,
		.stdout_backup = -1,
		._vec_children = NULL
	};

	if (shell_state.stdin_backup == -1)
		shell_state.stdin_backup = dup(STDIN_FILENO);
	if (shell_state.stdout_backup == -1)
		shell_state.stdout_backup = dup(STDOUT_FILENO);
	return (&shell_state);
}