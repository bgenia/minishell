/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:06:40 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/02 20:14:38 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/string/string.h>

int	builtin_echo(int argc, char **argv)
{
	if (argc > 3 && ft_strcmp(argv[1], "-n"))
		ft_printf("%s", argv[1]);
	ft_printf("%s/n", argv[1]);
	return (0);
}