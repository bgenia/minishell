/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:47:24 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 10:20:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>

#include <minishell/shell/shell_colors.h>

#include <libft/ctype.h>
#include <libft/convert.h>
#include <libft/io/printf.h>

static bool
	_parse_exit_code(char *str, intmax_t *result)
{
	*result = ft_atoi(str, NULL);
	return (errno != ERANGE);
}

int
	builtin_exit(int argc, char **argv)
{
	intmax_t	code;

	if (argc == 1)
		exit(0);
	if (!_parse_exit_code(argv[1], &code))
	{
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: exit: %s: numeric argument required\n" _TERM_RESET,
			argv[1]);
		exit(2);
	}
	exit((unsigned char)code);
	return (0);
}
