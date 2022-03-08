/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:38:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 04:42:53 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string/string.h>
#include <libft/array.h>

#include <minishell/builtins/builtins.h>

int	exec_builtin(char *name, char **argv)
{
	int	argc;

	argc = ft_arrlen(argv, sizeof(*argv));
	if (ft_streq(name, "echo"))
		builtin_echo(argc, argv);
	if (ft_streq(name, "cd"))
		builtin_cd(argc, argv);
	if (ft_streq(name, "pwd"))
		builtin_pwd(argc, argv);
	if (ft_streq(name, "export"))
		builtin_export(argc, argv);
	if (ft_streq(name, "unset"))
		builtin_unset(argc, argv);
	if (ft_streq(name, "env"))
		builtin_env(argc, argv);
	if (ft_streq(name, "exit"))
		builtin_exit(argc, argv);
	return (-1);
}
