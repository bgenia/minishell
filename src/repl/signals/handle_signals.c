/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/06 19:58:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>

#include <libft/io/printf.h>

#include <stdio.h>
#include <readline/readline.h>

#include <libft/vector/vector.h>

#include <minishell/repl/repl.h>

void	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		if (!g_repl_state.vec_children)
		{
			rl_on_new_line();
			rl_replace_line("", false);
			rl_redisplay();
		}
	}
	if (signal == SIGQUIT && g_repl_state.vec_children)
	{
		ft_printf("Quit\n");
		rl_on_new_line();
	}
}
