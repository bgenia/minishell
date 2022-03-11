/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:05:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/11 06:34:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stddef.h>

# include <minishell/lexer/token.h>
# include <minishell/parser/ast.h>

// External API

void
expand_env_variables(char **source);
void
expand_tokens(t_token *vec_tokens);
void
expand_executables(t_ast *ast);

// Internal API

typedef struct s_var_placeholder
{
	size_t	position;
	size_t	length;
}	t_var_placeholder;

bool
find_next_var_placeholder(char *source, t_var_placeholder *result);

char
*get_executable(char *path);

#endif
