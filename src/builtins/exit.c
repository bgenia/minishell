/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:47:24 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/20 08:40:04 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/types.h>
#include <libft/string/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <minishell/builtins.h>

int	is_number(char *str)
{
	int	result;
	int	i;
	int	strlen;

	result = -1;
	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	result = ft_atoi(str, NULL);
	return(result);
}

int	builtin_exit(int argc, char **argv)
{
	char	*exit_save_param;
	
	exit_save_param = calloc(sizeof(char), 1024);
	ft_strlcpy(exit_save_param, "?=0", 3);
	if (argc == 1)
	{
		builtin_export(1, &exit_save_param);
		free(exit_save_param);
		exit(0);
	}
	ft_strlcat(exit_save_param, ft_itoa((unsigned char)is_number(argv[1])), 10);
	builtin_export(1, &exit_save_param);
	if (is_number(argv[1]) < 0)
	{
		printf("exit: %s: numeric argument required\n", argv[1]);
		free(exit_save_param);
		exit(255);
	}
	free(exit_save_param);
	exit (is_number(argv[1]));
	return (0);
}