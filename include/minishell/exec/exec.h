/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:56:55 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/14 11:16:27 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include <minishell/lexer/token.h>
#include <minishell/parser/ast.h>

int	start_fork(t_parser *parser, char **env);



int run_command(t_ast *ast, char **env);

#endif