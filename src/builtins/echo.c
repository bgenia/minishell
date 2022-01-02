/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:06:40 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/02 19:18:11 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>

int	builtin_echo(int argc, char **argv)
{
	(void)argc;
	ft_printf("%s\n", argv[1]);
	return (0);
}