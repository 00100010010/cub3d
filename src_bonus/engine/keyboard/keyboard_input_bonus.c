/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:38:00 by jtrebes           #+#    #+#             */
/*   Updated: 2020/10/31 15:14:32 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void		keylock_settings(t_c *c)
{
	c->keylock.up_down = 0;
	c->keylock.rt = 0;
	c->keylock.lat = 0;
	if (c->key.lat_right || c->key.lat_left)
		c->keylock.lat = 1;
	if (c->key.down || c->key.up)
		c->keylock.up_down = 1;
	if (c->key.right || c->key.left)
		c->keylock.rt = 1;
}

void		define_mv(t_c *c)
{
	c->key.total = c->key.up + c->key.down + c->key.right
					+ c->key.left + c->key.lat_left + c->key.lat_right;
	if (c->key.total == 1)
		key1(c);
	else if (c->key.total == 2)
		key2(c);
	else if (c->key.total == 3)
		key3(c);
	else
		c->mv.mv = 0;
}

int			keyboard_input(int key, t_c *c)
{
	if (key == DOWN || key == S)
		c->key.down = 1;
	else if (key == UP || key == W)
		c->key.up = 1;
	else if (key == LAT_LEFT)
		c->key.lat_left = 1;
	else if (key == LAT_RIGHT)
		c->key.lat_right = 1;
	else if (key == LEFT)
		c->key.left = 1;
	else if (key == RIGHT)
		c->key.right = 1;
	else if (key == ESC)
		ft_close(c);
	else if (key == SPACE)
		c->key.space = 1;
	define_mv(c);
	return (0);
}

int			keyboard_release(int key, t_c *c)
{
	if (key == DOWN || key == S)
		c->key.down = 0;
	else if (key == UP || key == W)
		c->key.up = 0;
	else if (key == LAT_LEFT)
		c->key.lat_left = 0;
	else if (key == LAT_RIGHT)
		c->key.lat_right = 0;
	else if (key == LEFT)
		c->key.left = 0;
	else if (key == RIGHT)
		c->key.right = 0;
	else if (key == SPACE)
		c->key.space = 0;
	define_mv(c);
	return (0);
}
