/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_last_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:03:18 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 23:04:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/shell.h>

#include <libft/string/format.h>

void
	shell_set_last_status(int status)
{
	shell_get_state()->last_status = status;
	ft_format(
		shell_get_state()->last_status_string,
		4,
		"%d",
		status
		);
}
