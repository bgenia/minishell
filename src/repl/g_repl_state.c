/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_repl_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:22:38 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/21 18:47:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <minishell/repl/repl.h>

t_repl_state	g_repl_state = (t_repl_state){
	.vec_children = NULL
};
