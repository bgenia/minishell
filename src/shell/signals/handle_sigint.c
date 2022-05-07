/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sigint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:50:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 19:06:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

#include <minishell/shell/shell.h>
#include <ft/io/printf.h>

#include <readline/readline.h>

void
	handle_sigint(int signal)
{
	if (signal != SIGINT)
		return ;
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
