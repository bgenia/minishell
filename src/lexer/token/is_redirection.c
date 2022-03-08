/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:54:50 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:18:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <minishell/lexer/token.h>

bool
	is_redirection(t_token_type type)
{
	return (type == TOKEN_RL || type == TOKEN_RR
		|| type == TOKEN_RRA || type == TOKEN_RHD);
}
