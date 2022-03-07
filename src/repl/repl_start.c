/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:03:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 14:37:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include <minishell/repl/repl.h>

#include <libft/terminal/termdefs.h>
#include <libft/string/string.h>

#include <readline/readline.h>
#include <readline/history.h>

void
	repl_start(void)
{
	char	*line;

	while (true)
	{
		line = readline(g_shell_prompt);
		if (line == NULL)
		{
			break ;
		}
		if (ft_strisempty(line))
		{
			rl_on_new_line();
			continue ;
		}
		repl_eval(line);
		add_history(line);
		free(line);
	}
}
