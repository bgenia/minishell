/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:39:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 02:08:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>

int
builtin_cd(int argc, char **argv);

int
builtin_export(int argc, char **argv);

int
builtin_unset(int argc, char **argv);

int
builtin_exit(int argc, char **argv);

int
builtin_echo(int argc, char **argv);

int
builtin_pwd(int argc, char **argv);

int
builtin_env(int argc, char **argv);

#endif
