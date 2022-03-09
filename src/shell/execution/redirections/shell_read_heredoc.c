/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 07:33:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include <minishell/shell/shell.h>
#include <minishell/shell/shell_colors.h>

#include <libft/string/string.h>
#include <libft/memory/memory.h>
#include <libft/io/printf.h>

#include <readline/readline.h>

int
	shell_read_heredoc(char *name)
{
	char	*line;
	int		_pipe[2];

	pipe(_pipe);
	while (true)
	{
		line = readline(
				"\001" TERM_F_LIGHT_BLUE "\002" "doc> " "\001" TERM_RESET "\002"
				);
		if (!line && shell_match_last_signal(SIGINT))
			ft_dprintf(STDERR_FILENO, _TERM_F_YELLOW
				"minishell: warning: here-document "
				"delimited by SIGINT (wanted '%s')\n" _TERM_RESET, name);
		else if (!line)
			ft_dprintf(STDERR_FILENO, _TERM_F_YELLOW
				"minishell: warning: here-document "
				"delimited by end-of-file (wanted '%s')\n" _TERM_RESET, name);
		if (!line || ft_streq(line, name))
			break ;
		ft_dprintf(_pipe[1], "%s\n", line);
		free(line);
	}
	free(line);
	close(_pipe[1]);
	return (_pipe[0]);
}