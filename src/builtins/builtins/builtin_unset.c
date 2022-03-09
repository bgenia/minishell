/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:06:20 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 07:34:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/builtins/builtin_utils.h>
#include <minishell/shell/shell_colors.h>

#include <libft/system/env.h>
#include <libft/io/printf.h>

int
	builtin_unset(int argc, char **argv)
{
	(void)argc;
	if (validate_env_identifier(argv[1]))
	{
		ft_dprintf(STDERR_FILENO, _TERM_F_RED
			"minishell: %s: not a valid identifier" _TERM_RESET, argv[1]);
		return (1);
	}
	ft_unsetenv(argv[1]);
	return (0);
}
