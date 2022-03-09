/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:20:07 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 07:01:47 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/system/env.h>
#include <libft/terminal/termdefs.h>

int
	builtin_env(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		ft_dprintf(STDERR_FILENO, TERM_F_RED
			"minishell: env: %s: no such file or directory" TERM_RESET,
			argv[1]);
		return (127);
	}
	i = 0;
	while (environ[i])
		ft_printf("%s\n", environ[i++]);
	return (0);
}
