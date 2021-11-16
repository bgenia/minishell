/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:39:37 by bgenia            #+#    #+#             */
/*   Updated: 2021/11/16 19:23:08 by bgenia           ###   ########.fr       */
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

#endif
