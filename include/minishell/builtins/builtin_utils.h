/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 04:23:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 04:32:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

# include <stdbool.h>

# include <minishell/parser/ast.h>

int
exec_builtin(char *name, char **argv, int fd);

bool
is_builtin(char *name);

bool
is_builtin_command(t_ast_command *command);

bool
validate_env_identifier(char *identifier);

#endif
