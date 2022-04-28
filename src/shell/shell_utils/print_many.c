/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_many.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:46:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/25 22:47:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/printf.h>

void
	print_many(int fd, char c, size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		ft_dprintf(fd, "%c", c);
		i++;
	}
}
