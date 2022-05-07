/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sigquit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:56:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 19:06:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

#include <minishell/shell/shell.h>

#include <ft/io/printf.h>

#include <readline/readline.h>

void
	handle_sigquit(int signal)
{
	if (signal != SIGQUIT)
		return ;
}
