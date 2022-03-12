/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:20:47 by jtrebes           #+#    #+#             */
/*   Updated: 2020/10/27 19:42:45 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	lat(t_cam *cam, t_mv *mv, t_map *map)
{
	if (mv->mv == LAT_LEFT
			|| mv->mv == LAT_LEFT_UP
			|| mv->mv == LAT_LEFT_LEFT_UP
			|| mv->mv == LAT_LEFT_DOWN
			|| mv->mv == LAT_LEFT_LEFT_DOWN)
		mv_lat_left(cam, mv, map);
	else
		mv_lat_right(cam, mv, map);
}

void	up_down(t_cam *cam, t_mv *mv, t_map *map)
{
	if (mv->mv == UP
			|| mv->mv == RIGHT_UP
			|| mv->mv == LEFT_UP
			|| mv->mv == LAT_LEFT_UP
			|| mv->mv == LAT_RIGHT_UP
			|| mv->mv == LAT_LEFT_LEFT_UP
			|| mv->mv == LAT_RIGHT_RIGHT_UP)
		mv_up(cam, mv, map);
	else
		mv_down(cam, mv, map);
}

void	moving_engine(t_c *c)
{
	if (c->keylock.rt)
		mv_right_left(&c->cam, &c->mv);
	if (c->keylock.lat)
		lat(&c->cam, &c->mv, &c->map);
	if (c->keylock.up_down)
		up_down(&c->cam, &c->mv, &c->map);
}
