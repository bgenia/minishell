/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:06:20 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 02:48:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <libft/system/env.h>
#include <libft/io/printf.h>
#include <minishell/builtins/builtin_utils.h>

int
	builtin_unset(int argc, char **argv)
{
	(void)argc;
	if (validate_env_identifier(argv[1]))
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: not a valid identifier", argv[1]);
		return (1);
	}
	ft_unsetenv(argv[1]);
	return (0);
}
