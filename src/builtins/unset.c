/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:06:20 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/20 09:07:34 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include <libft/system/env.h>

int	builtin_unset(int argc, char **argv)
{
	(void)argc;
	ft_unsetenv(argv[1]);
	return (0);
}
