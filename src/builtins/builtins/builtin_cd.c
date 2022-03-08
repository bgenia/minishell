/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:48:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <libft/io/printf.h>
#include <libft/system/env.h>

int
	builtin_cd(int argc, char **argv)
{
	char	*dir;
	char	buffer[1024];

	dir = NULL;
	if (argc == 1)
		dir = ft_getenv("HOME");
	else
		dir = argv[1];
	if (chdir(dir) != 0)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: cd: %s: No such file or directory\n", dir);
		return (1);
	}
	if (getcwd(buffer, 1024))
		ft_setenv("OLDPWD", ft_getenv("PWD"), true);
	ft_setenv("PWD", buffer, true);
	return (0);
}
