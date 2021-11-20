/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:47:24 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/20 13:27:48 by ttanja           ###   ########.fr       */
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
	if (str)
		result = ft_atoi(str, NULL);
	return(result);
}

int	builtin_exit(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (argv[1] && is_number(argv[1]) < 0)
	{
		printf("exit: %s: numeric argument required\n", argv[1]);
		exit(255);
	}
	exit ((char)is_number(argv[1]));
	return (0);
}