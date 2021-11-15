/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:19:46 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 19:49:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <sys/wait.h>

#include <libft/string/string.h>
#include <libft/io/printf.h>
#include <libft/vector/vector.h>
#include <libft/system/env.h>

#include <minishell/repl/repl.h>
#include <minishell/repl/signals.h>
#include <minishell/expander/expander.h>
#include <minishell/builtins.h>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv)
{
	char	*line;
	t_ast	ast;

	(void)argc, (void)argv;
	rl_catch_signals = false;
	register_signal_handlers();
	while (true)
	{
		line = readline("msh> ");
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
			expand_executables(&ast);
			for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
			{
				t_ast_command command = ast.pipeline.vec_commands[i];
				for (size_t i = 0; i < ft_vector_get_size(command.vec_argv); i++)
					ft_printf("%s ", command.vec_argv[i]);
				ft_printf("\n");
				for (size_t i = 0; i < ft_vector_get_size(command.vec_redirections); i++)
					ft_printf("\t&%d '%s'\n", command.vec_redirections[i].fd, command.vec_redirections[i].file);
			}
			for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
			{
				if (is_builtin(ast.pipeline.vec_commands[i].vec_argv[0]))
				{
					exec_builtin(ast.pipeline.vec_commands[i].vec_argv[0], ast.pipeline.vec_commands[i].vec_argv);
					continue ;
				}
				g_repl_state.child_process_id = fork();
				if (g_repl_state.child_process_id == 0)
				{
					execve(ast.pipeline.vec_commands[i].vec_argv[0], ast.pipeline.vec_commands[i].vec_argv, environ);
				}
				waitpid(g_repl_state.child_process_id, NULL, 0);
				rl_on_new_line();
				g_repl_state.child_process_id = -1;
			}
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
