/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:31:36 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/01 05:54:10 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/reade_line/read_line.h>
#include <libft/string/string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_cat_last_str(char *input)
{
	char *str;

	str = ft_strdup(input);
	input = read_line();
	ft_strlcat(str, input, ft_strlen(str) + ft_strlen(input));
	free(input);
	return (str);
}
 
char *read_line(void)
{
	char *input;

	input = readline("Minishell> ");
	return(input);
}
