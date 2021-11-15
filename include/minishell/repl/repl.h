/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:42 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 18:38:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPL_H
# define REPL_H

# include <sys/types.h>

# include <minishell/parser/ast.h>

typedef struct s_repl_state
{
	pid_t	child_process_id;
}	t_repl_state;

extern t_repl_state g_repl_state;

typedef enum e_command_status
{
	COMMAND_OK,
	COMMAND_LEXICAL_ERROR,
	COMMAND_SYNTAX_ERROR
}	t_command_status;

t_command_status
parse_command(char *source, t_ast *result);

#endif
