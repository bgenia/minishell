/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdbool.h>
# include <sys/types.h>

# include <minishell/parser/ast.h>
# include <minishell/shell/execution/execution_context.h>

# include <ft/terminal/termdefs.h>

enum e_shell_state
{
	SHELL_WAITING,
	SHELL_READING_HEREDOC,
	SHELL_RUNNING
};

typedef struct s_shell_state
{
	int					stdin_backup;
	int					stdout_backup;
	enum e_shell_state	state;
	pid_t				last_child;
	int					last_status;
	char				last_status_string[4];
}	t_shell_state;

t_shell_state
*shell_get_state(void);
void
shell_set_last_status(int status);
void
shell_start(void);
int
shell_await_children(void);
void
shell_increment_level(void);

#endif
