/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:50:17 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/31 10:27:20 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stddef.h>
# include <stdbool.h>

// See docs/Parser.md for more info on token types
typedef enum e_token_type
{
	TOKEN_PIPE,
	TOKEN_RL,
	TOKEN_RR,
	TOKEN_RRA,
	TOKEN_RHD,
	TOKEN_WORD,
	TOKEN_SPACE
}	t_token_type;

bool
is_redirection(t_token_type type);

typedef struct s_token
{
	t_token_type	type;
	bool			expandable;
	int				fd;
	char			*value;
	size_t			position;
	size_t			length;
}	t_token;

#endif