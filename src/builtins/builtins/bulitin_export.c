/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:52:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <libft/string/string.h>
#include <libft/memory/memory.h>
#include <libft/system/env.h>
#include <libft/io/printf.h>
#include <minishell/builtins/builtin_utils.h>

static void
	_sort_string(char **cp_env, int count)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (ft_strcmp(cp_env[j], cp_env[j + 1]) > 0)
			{
				temp = cp_env[j];
				cp_env[j] = cp_env[j + 1];
				cp_env[j + 1] = temp;
			}
		}
	}
}

static void
	_print_sort_env(void)
{
	int		count;
	int		i;
	char	**cp_env;

	count = 0;
	i = -1;
	while (environ[count])
		count++;
	cp_env = ft_calloc(sizeof(char **), count + 1);
	while (++i < count)
		cp_env[i] = environ[i];
	cp_env[i] = NULL;
	_sort_string(cp_env, count);
	i = -1;
	while (++i < count)
		ft_printf("%s\n", cp_env[i]);
	free(cp_env);
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
