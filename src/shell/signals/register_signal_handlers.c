/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:24:37 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 18:54:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <signal.h>

#include <minishell/repl/signals.h>

void	register_signal_handlers(void)
{
	struct sigaction	signal_handler;

	signal_handler = (struct sigaction){0};
	signal_handler.sa_handler = handle_signals;
	sigaction(SIGINT, &signal_handler, NULL);
	sigaction(SIGQUIT, &signal_handler, NULL);
}
