/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 03:55:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdbool.h>
# include <sys/types.h>

# include <minishell/parser/ast.h>
# include <minishell/shell/execution/execution_context.h>

# include <libft/terminal/termdefs.h>

typedef struct s_shell_state
{
	int		stdin_backup;
	int		stdout_backup;
	bool	is_running;
	pid_t	*_vec_children;
	int		last_status;
	char	last_status_string[4];
}	t_shell_state;

t_shell_state
*shell_get_state(void);

void
shell_set_last_status(int status);

void
shell_start(void);

void
shell_register_child_process(pid_t pid);

int
shell_await_children(void);

#endif
