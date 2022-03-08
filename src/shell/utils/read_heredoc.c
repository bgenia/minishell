/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/08 02:51:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <libft/string/string.h>
#include <libft/memory/memory.h>

#include <readline/readline.h>

int	read_heredoc(char *name)
{
	char	*line;
	int		_pipe[2];

	pipe(_pipe);
	line = readline("heredoc> ");
	while (ft_strcmp(line, name))
	{
		write(_pipe[1], line, ft_strlen(line));
		write(_pipe[1], "\n", 1);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	close(_pipe[1]);
	return (_pipe[0]);
}
