/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:27:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 07:16:01 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/shell.h>
#include <minishell/shell/shell_utils.h>
#include <minishell/shell/execution/execution.h>

t_shell_result
	shell_execute_line(char *command)
{
	t_command_status	command_status;
	t_ast				ast;

	command_status = parse_command(command, &ast);
	if (command_status != COMMAND_OK)
		return (SHELL_ERROR);
	shell_execute_ast(&ast);
	ast_destroy(&ast);
	return (SHELL_OK);
}
