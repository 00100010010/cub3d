/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_engine_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:48:40 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 09:49:05 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	prepa_casting(t_ray *ray, t_map *map)
{
	if (!ray->side)
		ray->prpwalldist = fabs((ray->map_x - ray->pos_x +
										(1. - ray->step_x) / 2.) / ray->dir_x);
	else
		ray->prpwalldist = fabs((ray->map_y - ray->pos_y +
										(1. - ray->step_y) / 2.) / ray->dir_y);
	ray->h_line = (map->res_y / ray->prpwalldist);
	ray->draw_start = (int)-ray->h_line / 2 + map->res_y / 2;
	ray->draw_end = (int)ray->h_line / 2 + map->res_y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= map->res_y)
		ray->draw_end = map->res_y - 1;
	if (ray->side == 1)
		ray->wall_x = ray->pos_x + ((ray->map_y - ray->pos_y
						+ (1. - ray->step_y) / 2.) / ray->dir_y) * ray->dir_x;
	else
		ray->wall_x = ray->pos_y + ((ray->map_x - ray->pos_x
						+ (1. - ray->step_x) / 2.) / ray->dir_x) * ray->dir_y;
	ray->wall_x -= floor(ray->wall_x);
}

void	wall_hit(t_ray *ray, char **map)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (map[(int)ray->map_y][(int)ray->map_x] == '2' && !ray->sprt)
			ray->sprt = 1;
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->deltadistx;
			ray->map_x += ray->step_x;
			ray->side = 0.;
		}
		else
		{
			ray->side_dist_y += ray->deltadisty;
			ray->map_y += ray->step_y;
			ray->side = 1.;
		}
		if (map[(int)ray->map_y][(int)ray->map_x] == '1')
			hit = 1;
	}
}

void	vecteur_dir_longueur_seg(t_ray *ray)
{
	if (ray->dir_x < 0.)
	{
		ray->step_x = -1.;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->deltadistx;
	}
	else
	{
		ray->step_x = 1.;
		ray->side_dist_x = (ray->map_x + 1. - ray->pos_x) * ray->deltadistx;
	}
	if (ray->dir_y < 0.)
	{
		ray->step_y = -1.;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->deltadisty;
	}
	else
	{
		ray->step_y = 1.;
		ray->side_dist_y = (ray->map_y + 1. - ray->pos_y) * ray->deltadisty;
	}
}

void	pose_base(t_ray *ray, int res_x, t_cam *cam, int x)
{
	ray->map_x = (int)(cam->pos_x);
	ray->map_y = (int)(cam->pos_y);
	cam->camerax = (2. * (double)x / (double)res_x) - 1.;
	ray->pos_x = cam->pos_x;
	ray->pos_y = cam->pos_y;
	ray->dir_x = cam->dir_x + cam->plane_x * cam->camerax;
	ray->dir_y = cam->dir_y + cam->plane_y * cam->camerax;
	ray->deltadistx = sqrt(1 + (ray->dir_y * ray->dir_y) / (ray->dir_x
															* ray->dir_x));
	ray->deltadisty = sqrt(1 + (ray->dir_x * ray->dir_x) / (ray->dir_y
															* ray->dir_y));
}
