/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:19:46 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/10 21:37:42 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/io/printf.h>

#include <libft/vector/vector.h>

#include <minishell/lexer/lexer.h>
#include <minishell/lexer/token.h>

int	main(int argc, char **argv)
{
	t_token	*vec_tokens;
	t_lexer	lexer;
	size_t	i;

	(void)argc;
	vec_tokens = ft_vector_alloc_empty(sizeof(*vec_tokens));
	lexer = lexer_create(&vec_tokens);
	if (lexer_analyze(&lexer, argv[1]) != LEXER_OK)
		ft_dprintf(STDERR_FILENO, "Lexer error!\n");
	ft_printf("Token list [%u]:\n\n", ft_vector_get_size(vec_tokens));
	i = 0;
		ft_printf(
			":%d %d \"%s\"[%d] { fd: %d, expandable: %d }\n",
			vec_tokens[i].position,
			vec_tokens[i].type,
			vec_tokens[i].value,
			vec_tokens[i].length,
			vec_tokens[i].fd,
			vec_tokens[i].is_expandable
			);
		free(vec_tokens[i].value);
		i++;
	}
	ft_printf("\nEnd.\n");
	lexer_destroy(&lexer);
	ft_vector_free(vec_tokens);
}
