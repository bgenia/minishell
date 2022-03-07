/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:20:07 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/07 18:24:41 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/system/env.h>

int	builtin_env(int argc, char **argv, int fd)
{
	int	i;

	if (argc > 1)
	{
		ft_printf("env: %s: No such file or directory", argv[1]);
		return (127);
	}
	i = 0;
	(void)argc;
	(void)argv;
	while (environ[i])
		ft_dprintf(fd, environ[i++]);
	return (0);
}
