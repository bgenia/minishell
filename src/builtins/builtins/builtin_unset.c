/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:06:20 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 10:38:28 by bgenia           ###   ########.fr       */
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
	int	status;
	int	i;

	status = 0;
	i = 1;
	while (i < argc)
	{
		if (!validate_env_identifier(argv[i]))
		{
			ft_dprintf(STDERR_FILENO, _TERM_F_RED
				"minishell: unset: '%s': not a valid identifier\n" _TERM_RESET,
				argv[i]);
			status = 1;
		}
		else
		{
			ft_unsetenv(argv[i]);
		}
		i++;
	}
	return (status);
}
