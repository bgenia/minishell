/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:38:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/string.h>
#include <ft/array.h>

#include <minishell/builtins/builtins.h>

int
	exec_builtin(char *name, char **argv)
{
	int	argc;

	argc = ft_arrlen(argv, sizeof(*argv));
	if (!name || ft_streq(name, ":") || ft_streq(name, "true"))
		return (builtin_noop(argc, argv));
	if (ft_streq(name, "echo"))
		return (builtin_echo(argc, argv));
	if (ft_streq(name, "cd"))
		return (builtin_cd(argc, argv));
	if (ft_streq(name, "pwd"))
		return (builtin_pwd(argc, argv));
	if (ft_streq(name, "export"))
		return (builtin_export(argc, argv));
	if (ft_streq(name, "unset"))
		return (builtin_unset(argc, argv));
	if (ft_streq(name, "env"))
		return (builtin_env(argc, argv));
	if (ft_streq(name, "exit"))
		return (builtin_exit(argc, argv));
	return (-1);
}
