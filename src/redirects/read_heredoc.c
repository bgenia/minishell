/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/27 14:55:22 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <libft/string/string.h>
#include <libft/memory/memory.h>

char	*get_new_name(int *index)
{
	char *name;
	char *ind;
	
	ind = ft_calloc(sizeof(char), 2);
	ind[0] = *index + 48;
	ind[1] = '\0';
	name = ft_calloc(sizeof(char), 100);
	ft_strlcat(&name[0], "/tmp/heredoc_temp", 100);
	ft_strlcat(&name[12], ind, 100);
	free(ind);
	*index += + 1;
	return (name);
}

int	read_heredoc(char *name, int *index)
{
	char	*temp;
	char	*file_name;
	int		fd;
	
	file_name = get_new_name(index);
	printf("%s\n", file_name);
	fd = open(file_name, O_RDWR | O_CREAT);
	temp = readline("heredoc> ");
	while (ft_strcmp(temp, name))
	{
		write(fd, temp, ft_strlen(temp));
		write(fd, "\n", 1);
		free(temp);
		temp = readline("heredoc> ");
	}
	free(temp);
	free(file_name);
	return(fd);
}
