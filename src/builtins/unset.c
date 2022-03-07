/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:06:20 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/07 15:33:41 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <libft/system/env.h>
#include <libft/io/printf.h>
#include <minishell/builtins.h>

int	builtin_unset(int argc, char **argv)
{
	(void)argc;
	if (check_valid(argv[1]))
		{
			ft_printf("%s: : not a valid identifier", argv[1]);
			return (1);
		}
	ft_unsetenv(argv[1]);
	return (0);
}
