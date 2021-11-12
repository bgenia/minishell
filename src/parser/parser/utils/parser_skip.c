/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:30:40 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/09 20:31:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>

t_token	parser_skip(t_parser *parser, int count)
{
	parser->position += count;
	return (parser_peek(parser, 0));
}
