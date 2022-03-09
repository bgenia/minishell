/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 03:06:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <minishell/builtins/builtin_utils.h>

#include <libft/string/string.h>
#include <libft/memory/memory.h>
#include <libft/system/env.h>
#include <libft/io/printf.h>
#include <libft/array.h>

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

	status = 0;
	if (argc == 1)
		_print_sort_env();
	while (--argc > 0)
	{
		if (validate_env_identifier(argv[argc]))
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: export: %s: not a valid identifier\n", argv[argc]);
			status = 1;
			continue ;
		}
		ft_putenv(argv[argc]);
	}
	return (status);
}
