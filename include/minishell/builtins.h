/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:39:37 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/20 09:08:02 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>

int
exec_builtin(char *name, char **argv);

bool
is_builtin(char *name);

int
builtin_cd(int argc, char **argv);

int
builtin_export(int argc, char **argv);

int
builtin_unset(int argc, char **argv);

int
builtin_exit(int argc, char **argv);

#endif
