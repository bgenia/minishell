/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:38:11 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 20:08:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string/string.h>
#include <libft/array.h>

#include <minishell/builtins.h>

int	exec_builtin(char *name, char **argv)
{
	if (ft_streq(name, "cd"))
		builtin_cd(ft_arrlen(argv, sizeof(*argv)), argv);
	return (-1);
}
