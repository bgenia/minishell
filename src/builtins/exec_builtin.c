/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:38:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/02 21:42:08 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string/string.h>
#include <libft/array.h>

#include <minishell/builtins.h>

int	exec_builtin(char *name, char **argv)
{
	if (ft_streq(name, "echo"))
		builtin_echo(ft_arrlen(argv, sizeof(*argv)), argv);
	if (ft_streq(name, "cd"))
		builtin_cd(ft_arrlen(argv, sizeof(*argv)), argv);
	if (ft_streq(name, "pwd"))
		builtin_pwd(ft_arrlen(argv, sizeof(*argv)), argv);
	if (ft_streq(name, "export"))
		builtin_export(ft_arrlen(argv, sizeof(*argv)), argv);
	if (ft_streq(name, "unset"))
		builtin_unset(ft_arrlen(argv, sizeof(*argv)), argv);
	if (ft_streq(name, "env"))
		builtin_env(ft_arrlen(argv, sizeof(*argv)), argv);
	if (ft_streq(name, "exit"))
		builtin_exit(ft_arrlen(argv, sizeof(*argv)), argv);
	return (-1);
}
