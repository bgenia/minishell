/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:06:40 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/09 02:06:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/io/printf.h>
#include <libft/string/string.h>

int
	builtin_echo(int argc, char **argv)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (argc > 1 && !ft_strcmp(argv[1], "-n"))
		flag++;
	while (argv[i + flag])
	{
		ft_printf(argv[i + flag]);
		if ((argv[i + flag + 1]))
			ft_printf(" ");
		i++;
	}
	if (!flag)
		ft_printf("\n");
	return (0);
}
