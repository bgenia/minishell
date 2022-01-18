/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:36:03 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/18 14:38:17 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <libft/string/string.h>
#include <libft/memory/memory.h>

#include <readline/readline.h>

char	*read_heredoc(char *name)
{
	char	*input;
	char	*temp;
	char	*join;

	input = ft_calloc(1,1);
	temp = readline("heredoc> ");
	while (ft_strcmp(temp, name))
	{
		join = ft_strjoin(input, temp);
		free(temp);
		free(input);
		input = ft_strjoin(join, "\n");
		free(join);
		temp = readline("heredoc> ");
	}
	free(temp);
	return(input);
}
