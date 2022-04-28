/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:11:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/builtins/builtin_utils.h>
#include <minishell/shell/shell_colors.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>
#include <ft/process/env.h>
#include <ft/io/printf.h>
#include <ft/array.h>

static int
	_string_comparator(char **a, char **b, void *arg, size_t element_size)
{
	(void)arg, (void)element_size;
	return (ft_strcmp(*a, *b));
}

static void
	_print_sort_env(void)
{
	size_t	env_size;
	char	**env_copy;
	size_t	i;

	env_size = ft_arrlen(environ, sizeof(*environ));
	env_copy = ft_calloc(env_size + 1, sizeof(*env_copy));
	ft_arrcpy(env_copy, environ, sizeof(*environ), env_size);
	ft_qsort(env_copy, sizeof(*env_copy), env_size, (t_qsort_comparator){
		.arg = NULL,
		.comaprator = (void *) _string_comparator
	});
	i = 0;
	while (env_copy[i])
		ft_printf("declare -x %s\n", env_copy[i++]);
	free(env_copy);
}

int
	builtin_export(int argc, char **argv)
{
	int	status;
	int	i;

	status = 0;
	if (argc == 1)
		_print_sort_env();
	i = -1;
	while (++i < argc)
	{
		if (!validate_env_identifier(argv[i]))
		{
			ft_dprintf(STDERR_FILENO, "%sminishell: export: %s: not a valid "
				"identifier\n%s", shell_colorize(TERM_F_RED), argv[i],
				shell_colorize(TERM_RESET));
			status = 1;
			continue ;
		}
		else
		{
			ft_putenv(argv[i]);
		}
	}
	return (status);
}
