/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:43:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:19:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <libft/string/string.h>

bool
	is_builtin(char *name)
{
	if (ft_streq(name, "echo"))
		return (true);
	if (ft_streq(name, "cd"))
		return (true);
	if (ft_streq(name, "pwd"))
		return (true);
	if (ft_streq(name, "export"))
		return (true);
	if (ft_streq(name, "unset"))
		return (true);
	if (ft_streq(name, "env"))
		return (true);
	if (ft_streq(name, "exit"))
		return (true);
	return (false);
}
