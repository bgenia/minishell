/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:55:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 03:55:53 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include <minishell/parser/ast.h>
# include <minishell/shell/execution/execution_context.h>

void
shell_apply_redirections(t_ast_command *command, t_execution_context *ctx);

void
shell_close_redirections(t_ast_command *command);

void
shell_read_heredocs(t_ast *ast, t_execution_context *ctx);

void
shell_clear_heredocs(t_execution_context *ctx);

#endif
