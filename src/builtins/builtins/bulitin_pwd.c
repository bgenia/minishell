/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:22:35 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/printf.h>
#include <ft/process/env.h>

int
	builtin_pwd(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("%s\n", ft_getenv("PWD"));
	return (0);
}
