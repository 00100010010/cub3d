/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_wall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:37:50 by jim               #+#    #+#             */
/*   Updated: 2020/11/05 11:21:25 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		draw_walls(t_tex *tex, t_c *c, int x)
{
	double		y;
	int			color;

	tex->x = (int)(c->ray.wall_x * tex->w);
	if ((c->ray.side == 0 && c->ray.dir_x > 0)
									|| (c->ray.side == 1 && c->ray.dir_y < 0))
		tex->x = tex->w - tex->x - 1.;
	y = c->ray.draw_start;
	while (y < c->ray.draw_end)
	{
		tex->y = (int)((y * 2. - c->map.res_y + c->ray.h_line)
										* (tex->h / 2.) / c->ray.h_line);
		if (tex->y < 0)
			tex->y = 0;
		color = tex->addr[(int)(tex->y * tex->w + tex->x)];
		c->img.addr[(int)(y * c->map.res_x + x)] = color;
		y++;
	}
}

void		wall_casting(t_c *c, int x)
{
	vecteur_dir_longueur_seg(&c->ray);
	wall_hit(&c->ray, c->map.map);
	prepa_casting(&c->ray, &c->map);
	if (c->ray.side == 0 && c->ray.dir_x >= 0)
		draw_walls(&c->txtrs.wall_no, c, x);
	else if (c->ray.side == 0 && c->ray.dir_x < 0)
		draw_walls(&c->txtrs.wall_so, c, x);
	else if (c->ray.side == 1 && c->ray.dir_y >= 0)
		draw_walls(&c->txtrs.wall_we, c, x);
	else if (c->ray.side == 1 && c->ray.dir_y < 0)
		draw_walls(&c->txtrs.wall_ea, c, x);
}
