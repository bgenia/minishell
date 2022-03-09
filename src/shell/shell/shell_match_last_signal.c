/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_match_last_signal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 06:43:21 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 06:44:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <signal.h>

#include <minishell/shell/shell.h>

bool
	shell_match_last_signal(int signal)
{
	if (shell_get_state()->last_signal != signal)
		return (false);
	shell_get_state()->last_signal = 0;
	return (true);
}
