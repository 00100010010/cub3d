/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_cub3d.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:32:54 by jim               #+#    #+#             */
/*   Updated: 2020/11/07 15:42:18 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_CUB3D_H
# define KEYBOARD_CUB3D_H

# ifdef __linux__
#  define SPACE					49
#  define W						119
#  define A						97
#  define S						115
#  define D						100
#  define Q						113
#  define E						101
#  define ESC					65307
#  define LEFT					65361
#  define RIGHT					65363
#  define DOWN					65364
#  define UP					65362
#  define LAT_RIGHT 			E
#  define LAT_LEFT 				Q
#  define X_EVENT_KEY_EXIT 		33
#  define X_EVENT_KEY_PRESS		2
#  define X_EVENT_KEY_RELEASE 	3
# else
#  define Q 					12
#  define W 					13
#  define E 					14
#  define S 					1
#  define ESC 					53
#  define LEFT 					123
#  define RIGHT 				124
#  define DOWN 					125
#  define UP 					126
#  define SPACE 				49
#  define LAT_RIGHT				E
#  define LAT_LEFT				Q
#  define X_EVENT_KEY_PRESS		2
#  define X_EVENT_KEY_EXIT		17
#  define X_EVENT_KEY_RELEASE	3
# endif

# define LAT_LEFT_UP			555
# define LAT_RIGHT_UP			556
# define RIGHT_UP				557
# define LEFT_UP				558
# define LAT_LEFT_DOWN			559
# define LAT_RIGHT_DOWN			560
# define RIGHT_DOWN				561
# define LEFT_DOWN				562
# define LAT_LEFT_LEFT_DOWN		563
# define LAT_RIGHT_RIGHT_DOWN	564
# define LAT_LEFT_LEFT_UP		565
# define LAT_RIGHT_RIGHT_UP		566

#endif
