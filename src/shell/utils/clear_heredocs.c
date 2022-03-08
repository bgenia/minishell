/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:23:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:25:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/shell/execution/execution_context.h>

#include <libft/vector/vector.h>

void
	clear_heredocs(t_execution_context *ctx)
{
	ctx->vec_heredoc_fds = ft_vector_free(ctx->vec_heredoc_fds);
}
