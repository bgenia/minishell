/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:25:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/29 19:43:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_var_placeholder
{
	size_t	position;
	size_t	length;
}	t_var_placeholder;

bool
find_next_var_placeholder(char *source, t_var_placeholder *result);

void
string_expand_variables(char **source);

#endif
