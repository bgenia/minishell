/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:59:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 20:39:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include <minishell/shell/signals.h>
#include <minishell/shell/shell.h>

#include <libft/system/env.h>

#include <readline/readline.h>

int
	main(void)
{
	rl_catch_signals = false;
	register_signal_handlers();
	shell_start();
	ft_clearenv();
	return (0);
}
