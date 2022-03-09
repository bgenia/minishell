/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:18:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 07:29:21 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_COLORS_H
# define SHELL_COLORS_H

# include <libft/terminal/termdefs.h>

# ifndef USE_COLORS

#  define _TERM_F_RED ""
#  define _TERM_F_YELLOW ""
#  define _TERM_RESET ""

# else

#  define _TERM_F_RED TERM_F_RED
#  define _TERM_F_YELLOW TERM_F_YELLOW
#  define _TERM_RESET TERM_RESET

# endif

#endif
