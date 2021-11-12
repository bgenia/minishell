/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:19:46 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/12 22:57:35 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/io/printf.h>

#include <libft/vector/vector.h>

#include <libft/system/env.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

#include <minishell/parser/ast.h>
#include <minishell/parser/parser.h>
#include <minishell/parser/parser_utils.h>

#include <minishell/expander/expander.h>

#include <minishell/preparser/preparser.h>

int	main(int argc, char **argv)
{
	t_token	*vec_tokens;
	t_lexer	lexer;
	size_t	i;

	(void)argc;
	ft_printf("ARGV>> %s\n", argv[1]);
	vec_tokens = ft_vector_alloc_empty(sizeof(*vec_tokens));
	lexer = lexer_create(&vec_tokens);
	if (lexer_analyze(&lexer, argv[1]) != LEXER_OK)
		ft_dprintf(STDERR_FILENO, "Lexer error!\n");
	lexer_destroy(&lexer);
	for (size_t i = 0; i < ft_vector_get_size(vec_tokens); i++)
		if (vec_tokens[i].is_expandable)
			expand_env_variables(&vec_tokens[i].value);
	split_simple_words(&vec_tokens);
	merge_adjacent_words(&vec_tokens);
	remove_whitespaces(&vec_tokens);
	ft_printf("Token list [%u]:\n\n", ft_vector_get_size(vec_tokens));
	i = 0;
	while (i < ft_vector_get_size(vec_tokens))
	{
		ft_printf(
			":%d %d \"%s\"[%d] { fd: %d, expandable: %d }\n",
			vec_tokens[i].position,
			vec_tokens[i].type,
			vec_tokens[i].value,
			vec_tokens[i].length,
			vec_tokens[i].fd,
			vec_tokens[i].is_expandable
			);
		i++;
	}
	ft_printf("\nEnd.\n\n");
	t_ast ast;
	t_parser parser = parser_create(&ast);
	if (parser_parse(&parser, vec_tokens) != PARSER_OK)
	{
		ft_dprintf(STDERR_FILENO, "%S\n", create_parser_error_message(&parser.error_info));
	}
	else
	{
		ft_printf("Pipeline:\n");
		for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
		{
			t_ast_command command = ast.pipeline.vec_commands[i];
			ft_printf("\tCommand:");
			for (size_t i = 0; i < ft_vector_get_size(command.vec_argv); i++)
				ft_printf(" %s", command.vec_argv[i]);
			ft_printf("\n");
			for (size_t i = 0; i < ft_vector_get_size(command.vec_redirections); i++)
			{
				ft_printf("\t\tRedirection: fd=%d source='%s'\n", command.vec_redirections[i].fd, command.vec_redirections[i].source);
			}
		}
	}
	parser_destroy(&parser);
	for (size_t i = 0; i < ft_vector_get_size(vec_tokens); i++)
		free(vec_tokens[i].value);
	ft_vector_free(vec_tokens);
	for (size_t i = 0; i < ft_vector_get_size(ast.pipeline.vec_commands); i++)
	{
		for (size_t j = 0; j < ft_vector_get_size(ast.pipeline.vec_commands[i].vec_argv); j++)
			free(ast.pipeline.vec_commands[i].vec_argv[j]);
		for (size_t j = 0; j < ft_vector_get_size(ast.pipeline.vec_commands[i].vec_redirections); j++)
			free(ast.pipeline.vec_commands[i].vec_redirections[j].source);
		ft_vector_free(ast.pipeline.vec_commands[i].vec_argv);
		ft_vector_free(ast.pipeline.vec_commands[i].vec_redirections);
	}
	ft_vector_free(ast.pipeline.vec_commands);
	ft_clearenv();
}
