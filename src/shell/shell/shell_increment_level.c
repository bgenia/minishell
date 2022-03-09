/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_increment_level.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:53:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 22:59:18 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <minishell/shell/shell.h>

#include <libft/system/env.h>
#include <libft/string/format.h>

void
	shell_increment_level(void)
{
	char	buffer[4];

	ft_format(buffer, 4, "%d", ++shell_get_state()->shell_level);
	ft_setenv("SHLVL", buffer, true);
}
