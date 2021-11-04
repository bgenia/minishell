/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:32:17 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/04 18:12:35 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell/signal/ft_signal.h>

void	handler(int sig)
{
	if (sig == SIGINT)
		printf("signal");
	return ;
}



int	signal_init(void)
{
	int					pid;

	pid = 1;
	signal(SIGINT, handler);
	return (0);
}