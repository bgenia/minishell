/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env_identifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:03:29 by ttanja            #+#    #+#             */
/*   Updated: 2022/03/08 04:32:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <libft/types.h>

bool
	validate_env_identifier(char *identifier)
{
	int	i;
	int	check;

	if (identifier[0] != '_' && !ft_isalpha(identifier[0]))
		return (true);
	i = 0;
	check = 0;
	while (identifier[++i])
	{
		if (ft_isalpha(identifier[i])
			|| identifier[i] == '_'
			|| ft_isdigit(identifier[i])
			|| identifier[i] == '=')
			continue ;
		return (true);
	}
	return (false);
}
