/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:15:32 by ttanja            #+#    #+#             */
/*   Updated: 2021/11/01 13:47:26 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

typedef struct s_global_v
{
	char			*str;
	char			*str2;
	unsigned char	signal;
	unsigned char	flag;
	int				i;
	int				j;
}					t_global_v;

char	*read_line(void);
char	*ft_cat_last_str(char *input);


#endif