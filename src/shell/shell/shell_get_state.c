/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:46:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 22:57:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/shell/shell.h>

#include <libft/system/env.h>
#include <libft/convert.h>

t_shell_state
	*shell_get_state(void)
{
	static t_shell_state	shell_state = (t_shell_state){
		.state = SHELL_WAITING,
		.stdin_backup = -1,
		.stdout_backup = -1,
		.last_child = -1,
		.last_status = 0,
		.last_status_string = "0",
		.shell_level = -1
	};

	if (shell_state.stdin_backup == -1)
		shell_state.stdin_backup = dup(STDIN_FILENO);
	if (shell_state.stdout_backup == -1)
		shell_state.stdout_backup = dup(STDOUT_FILENO);
	if (shell_state.shell_level == -1)
		shell_state.shell_level = ft_atoi(ft_getenv("SHLVL"), NULL);
	return (&shell_state);
}
