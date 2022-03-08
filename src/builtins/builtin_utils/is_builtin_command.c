/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 04:32:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 04:33:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <minishell/parser/ast.h>
#include <minishell/builtins/builtin_utils.h>

bool
	is_builtin_command(t_ast_command *command)
{
	return (is_builtin(command->vec_argv[0]));
}
