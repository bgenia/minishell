/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:19:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 16:52:23 by bgenia           ###   ########.fr       */
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

#include <minishell/redirects/heredoc.h>

#include <signal.h>
#include <stddef.h>

// void	handle_sigpipe(int sig)
// {
// 	if (sig == SIGPIPE)
// 	{
// 		ft_dprintf(2, "BRUH_SIGPIPE!\n");
// 	}
// }

// void	register_sigpipe(void)
// {
// 	struct sigaction	signal_handler;

// 	signal_handler = (struct sigaction){0};
// 	signal_handler.sa_handler = handle_sigpipe;
// 	sigaction(SIGPIPE, &signal_handler, NULL);
// }


int	main(void)
{
	char	*line;
	t_ast	ast;

	rl_catch_signals = false;
	register_signal_handlers();
	while (true)
	{
		line = readline("\001" TERM_F_BLUE "\002" "msh> " "\001" TERM_RESET "\002");
		if (line == NULL)
		{
			// FIXME bruh
			free(line);
			break ;
		}
		if (ft_strisempty(line))
		{
			rl_on_new_line();
			continue ;
		}
		t_command_status parsing_status = parse_command(line, &ast);
		if (parsing_status == COMMAND_OK)
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

			int	*vec_heredoc_fds = ft_vector_alloc_empty(sizeof(*vec_heredoc_fds));

			for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
			{
				t_ast_command *command = &ast.pipeline.vec_commands[i];

				for (size_t j = 0; j < ft_vector_get_size(command->vec_redirections); j++)
				{
					t_ast_redirection *redirection = &command->vec_redirections[j];

					if (redirection->type != REDIR_HEREDOC)
						continue ;

					*(int *)ft_vector_push_back(&vec_heredoc_fds) = read_heredoc(redirection->file);
				}
			}

			int heredoc_index = 0;

			for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
			{
				if (is_builtin(ast.pipeline.vec_commands[i].vec_argv[0]))
				{
					exec_builtin(ast.pipeline.vec_commands[i].vec_argv[0], ast.pipeline.vec_commands[i].vec_argv, STDOUT_FILENO);
					continue ;
				}

				if (i < ft_vector_get_size(ast.pipeline.vec_commands) - 1)
				{
					pipe(_pipe);
				}

				pid_t current_child = fork();

				// signal(SIGPIPE, handle_sigpipe);

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
							file = vec_heredoc_fds[heredoc_index++];

						dup2(file, redirection->fd);
					}
					if (i < ft_vector_get_size(ast.pipeline.vec_commands) - 1)
					{
						close(_pipe[0]);
						dup2(_pipe[1], STDOUT_FILENO);
					}

					// register_sigpipe();
					// signal(SIGINT, SIG_IGN);
					// FIXME access()
					execve(ast.pipeline.vec_commands[i].vec_argv[0], ast.pipeline.vec_commands[i].vec_argv, environ);

					// close(_pipe[1]);
					// close(_pipe[0]);
					// Здесь нужно обработать ошибку если команда не смогла выполниться
					exit(-1);
				}


				*(pid_t*)ft_vector_push_back(&g_repl_state.vec_children) = current_child;

				for (size_t j = 0; j < ft_vector_get_size(ast.pipeline.vec_commands[i].vec_redirections); j++)
				{
					t_ast_redirection	*redirection;

					redirection = &ast.pipeline.vec_commands[i].vec_redirections[j];

					if (redirection->type == REDIR_HEREDOC)
						heredoc_index++;
				}

				if (i < ft_vector_get_size(ast.pipeline.vec_commands) - 1)
				{
					dup2(_pipe[0], STDIN_FILENO);
					close(_pipe[1]);
					close(_pipe[0]);
				}
				else
				{
					// close(_pipe[0]);
					// close(_pipe[1]);
					close(STDIN_FILENO);
				}
			}

			// for (size_t i = 0; i < ft_vector_get_size(g_repl_state.vec_children); i++)
			// 	waitpid(g_repl_state.vec_children[i], NULL, WNOHANG);
			int status;

			// int wpid;

			// while ((wpid = waitpid(-1, &status, 0)) > 0) ;

			for (size_t i = 0; i < ft_vector_get_size(g_repl_state.vec_children); i++)
			{
				waitpid(g_repl_state.vec_children[i], &status, 0);
			}


			// waitpid(-1, &status, 0);

			dup2(_stdin, STDIN_FILENO);
			dup2(_stdout, STDOUT_FILENO);

			// if ()
			ft_printf("Exit status: %d\n", WEXITSTATUS(status));
			ft_vector_free(g_repl_state.vec_children);
			ft_vector_free(vec_heredoc_fds);
			g_repl_state.vec_children = NULL;
			// rl_on_new_line();
		}
		add_history(line);
		free(line);
		if (parsing_status != COMMAND_LEXICAL_ERROR)
			ast_destroy(&ast);
	}
	ft_clearenv();
}
