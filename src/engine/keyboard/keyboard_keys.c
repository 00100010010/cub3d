/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 14:56:23 by jim               #+#    #+#             */
/*   Updated: 2020/11/03 22:05:58 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	key3(t_c *c)
{
	keylock_settings(c);
	c->mv.speed_walk = SPEED_WALK / 2;
	c->mv.rt = SPEED_ROTATION / 1.5;
	if (c->key.up && c->key.lat_right && c->key.right)
		c->mv.mv = LAT_RIGHT_RIGHT_UP;
	else if (c->key.up && c->key.lat_left && c->key.left)
		c->mv.mv = LAT_LEFT_LEFT_UP;
	else if (c->key.down && c->key.lat_right && c->key.right)
		c->mv.mv = LAT_RIGHT_RIGHT_DOWN;
	else if (c->key.down && c->key.lat_left && c->key.left)
		c->mv.mv = LAT_LEFT_LEFT_DOWN;
	if (c->mv.mv == LAT_RIGHT_RIGHT_DOWN
								|| c->mv.mv == LAT_LEFT_LEFT_UP)
		c->mv.rt *= -1;
}

void	key2_down(t_c *c)
{
	if (c->key.right)
		c->mv.mv = RIGHT_DOWN;
	else if (c->key.left)
		c->mv.mv = LEFT_DOWN;
	else if (c->key.lat_right)
		c->mv.mv = LAT_RIGHT_DOWN;
	else if (c->key.lat_left)
		c->mv.mv = LAT_LEFT_DOWN;
}

void	key2_up(t_c *c)
{
	if (c->key.lat_right)
		c->mv.mv = LAT_RIGHT_UP;
	else if (c->key.lat_left)
		c->mv.mv = LAT_LEFT_UP;
	else if (c->key.right)
		c->mv.mv = RIGHT_UP;
	else if (c->key.left)
		c->mv.mv = LEFT_UP;
}

void	key2(t_c *c)
{
	keylock_settings(c);
	if (c->key.up)
		key2_up(c);
	else if (c->key.down)
		key2_down(c);
	if (c->key.left)
		c->mv.rt = -SPEED_ROTATION / 1.5;
	else if (c->key.right)
		c->mv.rt = SPEED_ROTATION / 1.5;
	c->mv.speed_walk = SPEED_WALK / 1.3;
}

void	key1(t_c *c)
{
	keylock_settings(c);
	if (c->key.down)
		c->mv.mv = DOWN;
	else if (c->key.up)
		c->mv.mv = UP;
	else if (c->key.lat_right)
		c->mv.mv = LAT_RIGHT;
	else if (c->key.lat_left)
		c->mv.mv = LAT_LEFT;
	else if (c->key.right)
		c->mv.mv = RIGHT;
	else if (c->key.left)
		c->mv.mv = LEFT;
	if (c->key.right)
		c->mv.rt = SPEED_ROTATION;
	else if (c->key.left)
		c->mv.rt = -SPEED_ROTATION;
	else
		c->mv.speed_walk = SPEED_WALK;
}
