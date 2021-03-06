/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:27:29 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 19:04:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

void
handle_sigint(int signal);
void
handle_sigquit(int signal);

void
register_shell_signal_handlers(void);
void
register_default_signal_handlers(void);
void
ignore_signals(void);

#endif
