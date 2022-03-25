/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:59:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/25 22:33:42 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include <minishell/shell/signals.h>
#include <minishell/shell/shell.h>

#include <libft/system/env.h>
#include <libft/string/string.h>
#include <libft/system/env.h>

#include <readline/readline.h>

static void
	_process_args(int argc, char **argv)
{
	if (argc < 2)
		return ;
	if (ft_streq(argv[1], "-c") || ft_streq(argv[1], "--use-colors"))
		ft_setenv("MSH_USE_COLORS", "1", true);
}

int
	main(int argc, char **argv)
{
	_process_args(argc, argv);
	rl_catch_signals = false;
	register_signal_handlers();
	shell_start();
	ft_clearenv();
	return (0);
}
