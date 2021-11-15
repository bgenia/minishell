/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:38:17 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/14 16:21:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <libft/string/string.h>
#include <libft/string/format.h>
#include <libft/system/env.h>

static char	*_dup_if_executable(char *path)
{
	if (access(path, X_OK) == 0)
		return (ft_strdup(path));
	return (NULL);
}

static char	**_get_path_list(void)
{
	char	*env_path;

	env_path = ft_getenv("PATH");
	if (!env_path)
		return (NULL);
	return (ft_smsplit(env_path, ':'));
}

char	*get_executable(char *path)
{
	char	**env_path_list;
	char	test_path[1024];
	char	*result;
	int		i;

	if (ft_strchr(path, '/'))
		return (_dup_if_executable(path));
	env_path_list = _get_path_list();
	if (!env_path_list)
		return (NULL);
	result = NULL;
	i = 0;
	while (env_path_list[i] && !result)
	{
		ft_format(test_path, 1024, "%s/%s", env_path_list[i], path);
		result = _dup_if_executable(test_path);
		i++;
	}
	free(env_path_list);
	return (result);
}
