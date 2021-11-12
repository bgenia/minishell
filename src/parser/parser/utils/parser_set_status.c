/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:24:13 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/09 20:43:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>

t_parser_status	parser_set_status(t_parser *parser, t_parser_status status)
{
	parser->status = status;
	return (parser->status);
}
