/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 04:15:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdbool.h>
# include <sys/types.h>

# include <minishell/parser/ast.h>

# include <libft/terminal/termdefs.h>

const char	*g_shell_prompt = \
	"\001" TERM_F_BLUE "\002" "msh> " "\001" TERM_RESET "\002";
const char	*g_heredoc_prompt = \
	"\001" TERM_F_LIGHT_BLUE "\002" "doc> " "\001" TERM_RESET "\002";

typedef struct s_shell_state
{
	int		stdin_backup;
	int		stdout_backup;
	bool	is_running;
	pid_t	*_vec_children;

}	t_shell_state;

t_shell_state
*shell_get_state(void);

// void
// shell_init(void);

void
shell_start(void);

typedef enum e_shell_result
{
	SHELL_OK,
	SHELL_ERROR
}	t_shell_result;

int
shell_execute(char *command);

typedef struct s_execution_context
{
	t_ast	*ast;
	int		*vec_heredoc_fds;
	int		heredoc_index;
}	t_execution_context;

void
shell_execute_ast(t_ast *ast);

void
shell_register_child_process(pid_t pid);

int
shell_await_children(void);

void
shell_destroy(void);

#endif
