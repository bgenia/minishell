/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/25 14:32:56 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <libft/string/string.h>
#include <libft/memory/memory.h>

int	read_heredoc(char *name)
{
	char	*temp;
	int		fd;

	fd = open("/tmp/heredoc_temp", O_RDWR | O_CREAT);
	temp = readline("heredoc> ");
	while (ft_strcmp(temp, name))
	{
		write(fd, temp, ft_strlen(temp));
		write(fd, "\n", 1);
		free(temp);
		temp = readline("heredoc> ");
	}
	free(temp);
	return(fd);
}
