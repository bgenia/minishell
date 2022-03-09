/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_await_children.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:08:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 13:59:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <minishell/shell/shell.h>

#include <libft/io/printf.h>

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

	if (waitpid(shell_get_state()->last_child, &status, WUNTRACED) == -1)
		ft_dprintf(STDERR_FILENO, "Cringe\n");
	result = 1;
	while (result > 0)
		result = waitpid(-1, NULL, 0);
	return (_process_exit_status(status));
}
