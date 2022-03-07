/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 14:37:10 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPL_H
# define REPL_H

# include <sys/types.h>

# include <minishell/parser/ast.h>

const char	*g_shell_prompt = \
	"\001" TERM_F_BLUE "\002" "msh> " "\001" TERM_RESET "\002";
const char	*g_heredoc_prompt = \
	"\001" TERM_F_LIGHT_BLUE "\002" "doc> " "\001" TERM_RESET "\002";

typedef enum e_command_status
{
	COMMAND_OK,
	COMMAND_LEXICAL_ERROR,
	COMMAND_SYNTAX_ERROR
}	t_command_status;

t_command_status
parse_command(char *source, t_ast *result);

typedef struct s_repl_state
{
	bool	is_running;
	pid_t	*_vec_children;

}	t_repl_state;

// Global repl state (static variable hack)
t_repl_state
*repl_get_state(void);

void
repl_init(void);

void
repl_start(void);

void
repl_eval(char *command);

void
repl_run(t_ast *ast);

void
repl_register_child(pid_t pid);

int
repl_await_children(void);

void
repl_destroy(void);

#endif
