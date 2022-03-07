/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:36:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/07 11:19:50 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <libft/string/string.h>
#include <libft/memory/memory.h>
#include <libft/system/env.h>
#include <libft/io/printf.h>

void	sort_string(char **cp_env, int count)
{
	int		i;
	int		j;
	char	*temp;
	
	i = -1;
	while (++i < count)
	{
		j = -1;
		while(++j < count - 1)
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

void	print_sort_env(void)
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
	sort_string(cp_env, count);
	i = -1;
	while (++i < count)
		ft_printf("%s\n", cp_env[i]);
	free(cp_env);
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
