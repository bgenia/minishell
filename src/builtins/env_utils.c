/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:03:29 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/07 16:53:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/types.h>

int	check_valid(char *str)
{
	int	i;
	int	check;

	(void)check;
	if (str[0] == '_' || ft_isalpha(str[0]))
	{
		i = 0;
		check = 0;
		while (str[++i])
		{
			if (ft_isalpha(str[i]) || str[i] == '_' || ft_isdigit(str[i])
				|| str[i] == '=')
				continue ;
			return (1);
		}
	}
	else
		return (1);
	return (0);
}
