/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:24:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 13:57:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <signal.h>

#include <minishell/shell/signals.h>

void
	register_signal_handlers(void)
{
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, handle_signals);
}
