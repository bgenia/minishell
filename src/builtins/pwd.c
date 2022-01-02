/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:22:35 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/02 20:07:11 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/system/env.h>

int	builtin_pwd(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("%s\n", ft_getenv("pwd"));
	return (0);
}