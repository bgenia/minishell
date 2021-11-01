/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_whitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:16:22 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/01 12:07:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/vector/vector.h>

#include <minishell/lexer/token.h>

void	remove_whitespaces(t_token **token_vec_ptr)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(token_vec_ptr))
	{
		if ((*token_vec_ptr)[i].type == TOKEN_SPACE)
			ft_vector_remove_at(token_vec_ptr, i);
		else
			i++;
	}
}
