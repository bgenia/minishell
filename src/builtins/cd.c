/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/15 08:52:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <libft/system/env.h>

int	builtin_cd(int argc, char **argv)
{
	char	*dir;
	char	buffer[1024];

	if (argc == 1)
		dir = ft_getenv("HOME");
	else
		dir = argv[1];
	chdir(dir);
	if (getcwd(buffer, 1024))
		ft_setenv("PWD", buffer, true);
	return (0);
}
