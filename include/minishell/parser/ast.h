/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:51:06 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 18:49:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_ast_redirection_type
{
	REDIR_OUTPUT,
	REDIR_INPUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_ast_redirection_type;

typedef struct s_ast_redirection
{
	t_ast_redirection_type	type;
	int						fd;
	char					*file;
}	t_ast_redirection;

typedef struct s_ast_command
{
	t_ast_redirection	*vec_redirections;
	char				**vec_argv;
}	t_ast_command;

typedef struct s_ast_pipeline
{
	t_ast_command	*vec_commands;
}	t_ast_pipeline;

typedef struct s_ast
{
	t_ast_pipeline	pipeline;
}	t_ast;

void
ast_destroy(t_ast *ast);

#endif
