/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:47:24 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 02:12:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <libft/ctype.h>
#include <libft/convert.h>
#include <libft/string/string.h>

intmax_t
	is_number(char *str)
{
	intmax_t	result;
	size_t		length;

	result = ft_atoi(str, &length);
	if (length != ft_strlen(str))
		return (-1);
	return (result);
}

int
	builtin_exit(int argc, char **argv)
{
	intmax_t	code;

	if (argc == 1)
		exit(0);
	code = is_number(argv[1]);
	if (code < 0 || code > INT_MAX)
	{
		printf("exit: %s: numeric argument required\n", argv[1]);
		exit(255);
	}
	exit((char)code);
	return (0);
}
