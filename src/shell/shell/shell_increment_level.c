/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_increment_level.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:53:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <minishell/shell/shell.h>

#include <ft/process/env.h>
#include <ft/convert.h>
#include <ft/string/format.h>

void
	shell_increment_level(void)
{
	int		current_level;
	char	buffer[4];

	current_level = ft_atoi(ft_getenv("SHLVL"), NULL);
	ft_format(buffer, 4, "%d", ++current_level);
	ft_setenv("SHLVL", buffer, true);
}
