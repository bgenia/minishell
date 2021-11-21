/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:19:46 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/21 19:24:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <sys/wait.h>

#include <libft/string/string.h>
#include <libft/io/printf.h>
#include <libft/vector/vector.h>
#include <libft/system/env.h>
#include <libft/terminal/termdefs.h>

#include <minishell/repl/repl.h>
#include <minishell/repl/signals.h>
#include <minishell/expander/expander.h>
#include <minishell/builtins.h>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	t_ast	ast;

	(void)argc, (void)argv;
	rl_catch_signals = false;
	register_signal_handlers();
	while (true)
	{
		line = readline("\001" TERM_F_BLUE "\002" "msh> " "\001" TERM_RESET "\002");
		if (line == NULL)
		{
			free(line);
			break ;
		}
		if (ft_strisempty(line))
		{
			rl_on_new_line();
			continue ;
		}
		if (parse_command(line, &ast) == COMMAND_OK)
		{
			int		_pipe[2];
			int		_stdin;
			int		_stdout;

			_stdin = dup(STDIN_FILENO);
			_stdout = dup(STDOUT_FILENO);
			// int		fd_in = STDIN_FILENO;
			// int		fd_out = STDOUT_FILENO;

			g_repl_state.vec_children = ft_vector_alloc_with_capacity(sizeof(*g_repl_state.vec_children), ft_vector_get_size(ast.pipeline.vec_commands));

			expand_executables(&ast);
			for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
			{
				t_ast_command command = ast.pipeline.vec_commands[i];
				for (size_t i = 0; i < ft_vector_get_size(command.vec_argv); i++)
					ft_printf("'%s' ", command.vec_argv[i]);
				for (size_t i = 0; i < ft_vector_get_size(command.vec_redirections); i++)
					ft_printf(" &%d<->'%s'", command.vec_redirections[i].fd, command.vec_redirections[i].file);
				ft_printf("\n");
			}
			for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
			{
				if (is_builtin(ast.pipeline.vec_commands[i].vec_argv[0]))
				{
					exec_builtin(ast.pipeline.vec_commands[i].vec_argv[0], ast.pipeline.vec_commands[i].vec_argv);
					continue ;
				}

				if (i < ft_vector_get_size(ast.pipeline.vec_commands) - 1)
				{
					pipe(_pipe);
				}

				pid_t current_child = fork();

				if (current_child == 0)
				{
					for (size_t j = 0; j < ft_vector_get_size(ast.pipeline.vec_commands[i].vec_redirections); j++)
					{
						t_ast_redirection	*redirection;

						redirection = &ast.pipeline.vec_commands[i].vec_redirections[j];

						if (redirection->fd == -1 && (redirection->type == REDIR_APPEND || redirection->type == REDIR_OUTPUT))
							redirection->fd = STDOUT_FILENO;
						if (redirection->fd == -1 && (redirection->type == REDIR_INPUT || redirection->type == REDIR_HEREDOC))
							redirection->fd = STDIN_FILENO;

						int file;

						if (redirection->type == REDIR_APPEND)
							file = open(redirection->file, O_WRONLY | O_APPEND | O_CREAT, 0666);
						else if (redirection->type == REDIR_OUTPUT)
							file = open(redirection->file, O_WRONLY | O_CREAT, 0666);
						else if (redirection->type == REDIR_INPUT)
							file = open(redirection->file, O_RDONLY);
						else
							file = redirection->fd;

						if (redirection->type == REDIR_HEREDOC)
							ft_dprintf(redirection->fd, "%s", redirection->file);

						dup2(file, redirection->fd);
					}
					if (i < ft_vector_get_size(ast.pipeline.vec_commands) - 1)
					{
						dup2(_pipe[1], STDOUT_FILENO);
					}
					execve(ast.pipeline.vec_commands[i].vec_argv[0], ast.pipeline.vec_commands[i].vec_argv, environ);
				}
				else
				{
					*(pid_t*)ft_vector_push_back(&g_repl_state.vec_children) = current_child;
				}

				if (i < ft_vector_get_size(ast.pipeline.vec_commands) - 1)
				{
					dup2(_pipe[0], STDIN_FILENO);
					close(_pipe[1]);
				}
			}

			// for (size_t i = 0; i < ft_vector_get_size(g_repl_state.vec_children); i++)
			// 	waitpid(g_repl_state.vec_children[i], NULL, WNOHANG);
			int status;

			waitpid(-1, &status, 0);

			dup2(_stdin, STDIN_FILENO);
			dup2(_stdout, STDOUT_FILENO);

			ft_printf("Exit status: %d\n", WEXITSTATUS(status));
			ft_vector_free(g_repl_state.vec_children);
			g_repl_state.vec_children = NULL;
			rl_on_new_line();
		}
		else
		{
			ft_printf("Syntax error!\n");
		}
		add_history(line);
		free(line);
		ast_destroy(&ast);
	}
	ft_clearenv();
}
