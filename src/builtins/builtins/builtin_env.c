/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:20:07 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/25 22:38:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/shell_colors.h>

#include <libft/io/printf.h>
#include <libft/system/env.h>

int
	builtin_env(int argc, char **argv)
{
	int	i;

	(void)argv;
	if (argc > 1)
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: env: too many arguments\n%s",
			shell_colorize(TERM_F_RED), shell_colorize(TERM_RESET));
		return (2);
	}
	i = 0;
	while (environ[i])
		ft_printf("%s\n", environ[i++]);
	return (0);
}
