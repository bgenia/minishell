/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:06:40 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/07 23:47:02 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/io/printf.h>
#include <libft/string/string.h>


int	builtin_echo(int argc, char **argv, int fd)
{
	int	flag;
	int i;
	
	flag = 0;
	i = 1;
	if (argc > 1 && !ft_strcmp(argv[1], "-n"))
		flag++;
	while (argv[i + flag])
	{
		ft_dprintf(fd, argv[i + flag]);
		if ((argv[i + flag + 1]))
			ft_dprintf(fd, " ");
		i++;
	}
	if (!flag)
		ft_dprintf(fd, "\n");
	return (0);
}
