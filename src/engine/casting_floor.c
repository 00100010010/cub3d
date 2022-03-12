/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:38:44 by jim               #+#    #+#             */
/*   Updated: 2020/11/04 09:40:04 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				pick_color_floor(t_tex *tex, t_ray *ray)
{
	if (tex->name)
	{
		tex->x = (int)((ray->deltadistx * ray->map_x + (1.0 - ray->deltadistx)
											* ray->pos_x) * tex->w) % tex->w;
		tex->y = (int)((ray->deltadistx * ray->map_y + (1.0 - ray->deltadistx)
											* ray->pos_y) * tex->h) % tex->h;
		return (tex->addr[(int)(tex->y * tex->w + tex->x)]);
	}
	else
		return (rgb(tex->rgb[0], tex->rgb[1], tex->rgb[2]));
}

void			floor_casting_adjust(t_ray *ray)
{
	if (ray->side == 0)
		ray->map_y += ray->wall_x;
	if (ray->side == 0 && ray->dir_x < 0)
		ray->map_x += 1.0;
	else if (ray->side == 1)
		ray->map_x += ray->wall_x;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->map_y += 1.0;
}

void			floor_casting(t_c *c, int x)
{
	int			color;
	double		y;
	double		z;

	floor_casting_adjust(&c->ray);
	y = c->ray.draw_end;
	while (y < c->map.res_y)
	{
		c->ray.deltadistx = ((c->map.res_y / (2 * y - c->map.res_y)))
														/ (c->ray.prpwalldist);
		color = pick_color_floor(&c->txtrs.floor, &c->ray);
		c->img.addr[(int)(y * c->map.res_x + x)] = color;
		color = pick_color_floor(&c->txtrs.sky, &c->ray);
		c->img.addr[(int)((c->map.res_y - y - 1) * c->map.res_x + x)] = color;
		y++;
	}
}
