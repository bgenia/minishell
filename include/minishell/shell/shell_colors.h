/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:18:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 07:57:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_COLORS_H
# define SHELL_COLORS_H

# include <libft/terminal/termdefs.h>

# ifdef NO_COLORS

#  ifdef USE_COLORS
#   undef USE_COLORS
#  endif

#  undef TERM_F_BLUE
#  undef TERM_F_LIGHT_BLUE
#  undef TERM_RESET

#  define TERM_F_BLUE ""
#  define TERM_F_LIGHT_BLUE ""
#  define TERM_RESET ""

# endif

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
