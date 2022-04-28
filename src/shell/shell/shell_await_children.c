/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_await_children.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:08:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <minishell/shell/shell.h>

#include <ft/io/printf.h>

static int
	_process_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}

int
	shell_await_children(void)
{
	int	status;
	int	result;

	waitpid(shell_get_state()->last_child, &status, 0);
	result = 1;
	while (result > 0)
		result = waitpid(-1, NULL, 0);
	return (_process_exit_status(status));
}
