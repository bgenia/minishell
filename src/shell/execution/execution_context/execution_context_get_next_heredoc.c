/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_context_get_next_heredoc.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:02:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 23:09:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/execution/execution_context.h>

int
	execution_context_get_next_heredoc(t_execution_context *ctx)
{
	return (ctx->vec_heredoc_fds[ctx->heredoc_index++]);
}
