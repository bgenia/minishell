/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:39:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/08 10:42:15 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>

int
exec_builtin(char *name, char **argv, int fd);

bool
is_builtin(char *name);

int
builtin_cd(int argc, char **argv);

int
builtin_export(int argc, char **argv, int fd);

int
builtin_unset(int argc, char **argv);

int
builtin_exit(int argc, char **argv);

int
builtin_echo(int argc, char **argv, int fd);

int
builtin_pwd(int argc, char **argv);

int
builtin_env(int argc, char **argv, int fd);

int
check_valid(char *str);

#endif
