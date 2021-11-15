/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:00 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 18:55:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <libft/io/printf.h>

#include <stdio.h>
#include <readline/readline.h>

#include <minishell/repl/repl.h>

void	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		if (g_repl_state.child_process_id != -1)
			kill(g_repl_state.child_process_id, SIGINT);
		rl_on_new_line();
		if (g_repl_state.child_process_id == -1)
			rl_redisplay();
	}
	if (signal == SIGQUIT && g_repl_state.child_process_id != -1)
	{
		kill(g_repl_state.child_process_id, SIGQUIT);
		ft_printf("Quit\n");
		rl_on_new_line();
	}
}
