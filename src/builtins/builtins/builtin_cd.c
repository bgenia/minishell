/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/shell/shell_colors.h>

#include <ft/io/printf.h>
#include <ft/process/env.h>

int
	builtin_cd(int argc, char **argv)
{
	char	*dir;
	char	buffer[1024];

	if (argc > 2)
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: cd: too many arguments\n%s",
			shell_colorize(TERM_F_RED), shell_colorize(TERM_RESET));
		return (2);
	}
	dir = NULL;
	if (argc == 1)
		dir = ft_getenv("HOME");
	else
		dir = argv[1];
	if (chdir(dir) != 0)
	{
		ft_dprintf(STDERR_FILENO, "%sminishell: cd: %s: No such file or"
			" directory\n%s", shell_colorize(TERM_F_RED), dir,
			shell_colorize(TERM_RESET));
		return (1);
	}
	if (getcwd(buffer, 1024))
		ft_setenv("OLDPWD", ft_getenv("PWD"), true);
	ft_setenv("PWD", buffer, true);
	return (0);
}
