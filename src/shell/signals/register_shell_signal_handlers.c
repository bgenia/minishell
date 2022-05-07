/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_shell_signal_handlers.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:24:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 19:00:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <minishell/shell/signals.h>

void
	register_shell_signal_handlers(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
