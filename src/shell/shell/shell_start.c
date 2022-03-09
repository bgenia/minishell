/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:01:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 11:45:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <minishell/shell/shell.h>
#include <minishell/shell/execution/execution.h>
#include <minishell/shell/shell_colors.h>

#include <libft/string/string.h>

#include <readline/readline.h>
#include <readline/history.h>

void
	shell_start(void)
{
	char	*line;

	while (true)
	{
		line = readline(
				"\001" TERM_F_BLUE "\002" "msh> " "\001" TERM_RESET "\002"
				);
		if (line == NULL)
		{
			break ;
		}
		if (ft_strisempty(line))
		{
			rl_on_new_line();
			free(line);
			continue ;
		}
		shell_execute_line(line);
		add_history(line);
		free(line);
	}
}
