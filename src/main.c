/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:31:43 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/01 13:44:11 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/heredoc/heredoc.h>
#include <minishell/reade_line/read_line.h>
#include <signal.h>
#include <libft/memory/memory.h>
#include <libft/string/string.h>

t_global_v *g_val;

int	main(int argc, char const *argv[], char const *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	g_val = ft_calloc(sizeof(t_global_v), 1);
	if (!g_val)
		return (1);
	while (1)
	{
		g_val->str = read_line();
		if (!ft_strcmp(g_val->str, "exit"))
			break;
		if (ft_strnstr(g_val->str, "<<", ft_strlen(g_val->str)))
		{
			g_val->str2 =  read_heredoc(get_name_heredoc(g_val->str));
			printf("%s\n", g_val->str2);
		}
		// продолжение следует
	}
	return (0);
}
  