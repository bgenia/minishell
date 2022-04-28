/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_colorize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:29:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/shell.h>

#include <ft/process/env.h>

char
	*shell_colorize(char *color_code)
{
	if (ft_getenv("MSH_USE_COLORS"))
		return (color_code);
	return ("");
}
