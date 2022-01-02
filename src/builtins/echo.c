/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:06:40 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/02 22:14:14 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/io/printf.h>
#include <libft/string/string.h>

int	builtin_echo(int argc, char **argv)
{
	int	flag;
	int i;
	
	flag = 0;
	i = 1;
	if (argc > 3 && ft_strcmp(argv[1], "-n"))
		flag++;
	while (argv[i])
	{
		ft_printf("%s", argv[i]);
		if ((argv[i + 1]))
			ft_printf("%s", " ");
	}
	if (!flag)
		write(1, "\n", 1);
	return (0);
}
