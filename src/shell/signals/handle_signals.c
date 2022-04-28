/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

#include <minishell/shell/shell.h>
#include <minishell/shell/signals.h>

#include <ft/io/printf.h>
#include <ft/vector/vector.h>

#include <readline/readline.h>

void
	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		if (shell_get_state()->state != SHELL_READING_HEREDOC)
		{
			ft_printf("\n");
		}
		if (shell_get_state()->state == SHELL_WAITING)
		{
			shell_set_last_status(128 + SIGINT);
			rl_on_new_line();
			rl_replace_line("", false);
			rl_redisplay();
		}
	}
	if (signal == SIGQUIT && shell_get_state()->state == SHELL_RUNNING)
	{
		ft_printf("Quit\n");
		rl_on_new_line();
	}
}
