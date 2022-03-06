/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 00:05:08 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <libft/string/string.h>
#include <libft/memory/memory.h>
#include <libft/system/env.h>
#include <libft/io/printf.h>

void	sort_string(char ***strings, int count)
{
	int		i;
	int		j;
	char	*temp;
	
	i = -1;
	while (++i < count)
	{
		j = -1;
		while(++j < count)
		{
			if (ft_strcmp(*strings[j], *strings[j +1]) > 0)
			{
				temp = *strings[j];
				*strings[j] = *strings[j + 1];
				*strings[j + 1] = temp;
				ft_printf("%d\n",j);
			}
		}
	}
}

void	print_sort_env(void)
{
	int		env_count;
	int		i;
	char	**cp_env;

	env_count = 0;
	i = -1;
	while (environ[env_count])
		env_count++;
	cp_env = ft_calloc(sizeof(void), env_count);
	while (++i < env_count)
		cp_env[i] = environ[i];
	sort_string(&cp_env, env_count);
	i = -1;
	while (++i < env_count)
		ft_printf("%s\n", cp_env[i]);

}


int	builtin_export(int argc, char **argv)
{
	if (argc == 1)
		print_sort_env();
	while (--argc > 0)
	{
		ft_putenv(argv[argc]);
	}
	return (0);
}
