/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_apply_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:53:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/25 21:15:05 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <minishell/parser/ast.h>
#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution_context.h>
#include <minishell/shell/shell_colors.h>

#include <libft/vector/vector.h>
#include <libft/io/printf.h>

static void
	_normalize_redirection_fd(t_ast_redirection *redirection)
{
	if (redirection->fd == -1
		&& (redirection->type == REDIR_APPEND
			|| redirection->type == REDIR_OUTPUT))
		redirection->fd = STDOUT_FILENO;
	if (redirection->fd == -1
		&& (redirection->type == REDIR_HEREDOC
			|| redirection->type == REDIR_INPUT))
		redirection->fd = STDIN_FILENO;
}

// Does not detect ambigous redirects like bash, it's just a placeholder
static void
	_handle_redirection_error(t_ast_redirection *redirection)
{
	if (errno == EISDIR)
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: is a directiory\n" _TERM_RESET,
			redirection->file);
	else if (errno == EACCES)
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: permission denied\n" _TERM_RESET,
			redirection->file);
	else if (errno == ENOENT)
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: no such file or directory\n" _TERM_RESET,
			redirection->file, errno);
	else
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: ambigous redirect\n" _TERM_RESET,
			redirection->file);
	exit(EXIT_FAILURE);
}

static void
	_apply_redirection(t_ast_redirection *redirection, t_execution_context *ctx)
{
	int	file;

	if (redirection->type == REDIR_APPEND)
		file = open(redirection->file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	else if (redirection->type == REDIR_OUTPUT)
		file = open(redirection->file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	else if (redirection->type == REDIR_INPUT)
		file = open(redirection->file, O_RDONLY);
	else
		file = execution_context_get_next_heredoc(ctx);
	if (file == -1)
		_handle_redirection_error(redirection);
	else
		dup2(file, redirection->fd);
}

void
	shell_apply_redirections(t_ast_command *command, t_execution_context *ctx)
{
	size_t				i;
	t_ast_redirection	*redirection;

	i = 0;
	while (i < ft_vector_get_size(command->vec_redirections))
	{
		redirection = &command->vec_redirections[i];
		_normalize_redirection_fd(redirection);
		_apply_redirection(redirection, ctx);
		i++;
	}
}
