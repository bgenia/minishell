/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/01 13:52:36 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/reade_line/read_line.h>
#include <libft/string/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft/memory/memory.h>

char	*get_name_heredoc(char *str)
{
	size_t	i;
	size_t	j;
	char	*name;

	i = 1;
	while(str[i] && str[i - 1] != '<' && str[i] != '<')
		i++;
	j = i;
while(str[j] && str[j] != '\n')
		j++;
	name = calloc(sizeof(char), j - i + 1);
	ft_strlcpy(name, &str[i + 2], j - i );
	return(name);
}

char	*read_heredoc(char *name)
{
	char	*input;
	char	*temp;

	input = ft_calloc(1,1);
	temp = readline("heredoc> ");
	if (!ft_strcmp(temp, name))
		return ("");
	while (ft_strcmp(temp, name))
	{
		ft_strjoin(input, temp);
		free(temp);
		temp = readline("heredoc> ");
	}
	ft_strjoin(input, temp);
	free(temp);
	return(input);
}