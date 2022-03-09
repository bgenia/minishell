/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_await_children.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:08:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 04:43:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <minishell/shell/shell.h>

#include <libft/vector/vector.h>

// FIXME
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
	pid_t	*children;
	size_t	i;
	int		status;

	children = shell_get_state()->_vec_children;
	i = 0;
	while (i < ft_vector_get_size(children))
	{
		waitpid(children[i], &status, 0);
		i++;
	}
	ft_vector_free(children);
	shell_get_state()->_vec_children = NULL;
	return (_process_exit_status(status));
}
