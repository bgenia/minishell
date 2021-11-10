/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:50:17 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/09 21:35:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stddef.h>
# include <stdbool.h>

// See docs/Parser.md for more info on token types
typedef enum e_token_type
{
	TOKEN_PIPE	= 1 << 0,
	TOKEN_RL	= 1 << 1,
	TOKEN_RR	= 1 << 2,
	TOKEN_RRA	= 1 << 3,
	TOKEN_RHD	= 1 << 4,
	TOKEN_WORD	= 1 << 5,
	TOKEN_SPACE	= 1 << 6,
	TOKEN_EOF	= 1 << 7
}	t_token_type;

bool
is_redirection(t_token_type type);

typedef struct s_token
{
	t_token_type	type;
	bool			is_expandable;
	bool			is_quoted;
	int				fd;
	char			*value;
	size_t			position;
	size_t			length;
}	t_token;

#endif
