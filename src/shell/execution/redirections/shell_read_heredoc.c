/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/30 10:54:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include <minishell/shell/shell.h>
#include <minishell/shell/shell_colors.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>
#include <ft/io/printf.h>
#include <ft/string/format.h>

#include <readline/readline.h>

static char
	*_create_heredoc_prompt(char *name)
{
	return (ft_aformat("\001" TERM_F_LIGHT_BLUE "\002" "doc(" "\001" TERM_RESET
			"\002" "%s" "\001" TERM_F_LIGHT_BLUE "\002" ")> " "\001" TERM_RESET
			"\002", name));
}

int
	shell_read_heredoc(char *name)
{
	char	*prompt;
	char	*line;
	int		_pipe[2];

	pipe(_pipe);
	prompt = _create_heredoc_prompt(name);
	while (true)
	{
		line = readline(prompt);
		if (!line)
			ft_dprintf(STDERR_FILENO, "%sminishell: warning: here-document "
				"delimited by end-of-file (wanted '%s')\n%s",
				shell_colorize(TERM_F_YELLOW), name,
				shell_colorize(TERM_RESET));
		if (!line || ft_streq(line, name))
			break ;
		ft_dprintf(_pipe[1], "%s\n", line);
		free(line);
	}
	free(line);
	free(prompt);
	close(_pipe[1]);
	return (_pipe[0]);
}
