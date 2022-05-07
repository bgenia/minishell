/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_default_signal_handlers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:59:30 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 19:00:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void
	register_default_signal_handlers(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
