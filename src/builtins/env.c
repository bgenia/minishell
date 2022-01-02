/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:20:07 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/02 22:12:30 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/system/env.h>

int	builtin_env(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	(void)argv;
	while (environ[i])
		ft_printf("%s\n", environ[i++]);
	return (0);
}