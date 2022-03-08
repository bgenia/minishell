/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:15:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

#include <minishell/shell/shell.h>
#include <minishell/shell/signals.h>

#include <libft/io/printf.h>
#include <libft/vector/vector.h>

#include <readline/readline.h>

void
	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		if (!shell_get_state()->is_running)
		{
			rl_on_new_line();
			rl_replace_line("", false);
			rl_redisplay();
		}
	}
	if (signal == SIGQUIT && shell_get_state()->is_running)
	{
		ft_printf("Quit\n");
		rl_on_new_line();
	}
}
