/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:13:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/06 23:15:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void
	process_command(char *line)
{
	int		std_fd_backup[2];

	std_fd_backup[0] = dup(STDIN_FILENO);
	std_fd_backup[1] = dup(STDOUT_FILENO);
}
