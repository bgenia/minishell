/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:17:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:16:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/parser/parser.h>
#include <minishell/parser/ast.h>

t_parser
	parser_create(t_ast *ast)
{
	return ((t_parser){.status = PARSER_OK, .error_info = {0}, .ast = ast});
}
