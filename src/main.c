/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:59:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 20:21:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include <minishell/shell/signals.h>
#include <minishell/shell/shell.h>

#include <ft/process/env.h>
#include <ft/string/string.h>
#include <ft/process/env.h>

#include <readline/readline.h>

static void
	_process_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return ;
	i = 1;
	while (i < argc)
	{
		if (ft_streq(argv[i], "-c") || ft_streq(argv[i], "--use-colors"))
			ft_setenv("MSH_USE_COLORS", "1", true);
		if (ft_streq(argv[i], "-e") || ft_streq(argv[i], "--detailed-errors"))
			ft_setenv("MSH_USE_DETAILED_ERRORS", "1", true);
	}
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
