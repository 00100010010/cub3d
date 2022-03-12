/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_engine_directions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:53:00 by jim               #+#    #+#             */
/*   Updated: 2020/10/27 19:42:41 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	mv_right_left(t_cam *cam, t_mv *mv)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = cam->dir_x;
	old_plane_x = cam->plane_x;
	cam->dir_x = cam->dir_x * cos(-mv->rt) - cam->dir_y * sin(-mv->rt);
	cam->dir_y = old_dir_x * sin(-mv->rt) + cam->dir_y * cos(-mv->rt);
	cam->plane_x = cam->plane_x * cos(-mv->rt) - cam->plane_y * sin(-mv->rt);
	cam->plane_y = old_plane_x * sin(-mv->rt) + cam->plane_y * cos(-mv->rt);
}

void	mv_lat_left(t_cam *cam, t_mv *mv, t_map *map)
{
	if (map->map[(int)floor(cam->pos_y)]
				[(int)floor(cam->pos_x - cam->plane_x * mv->speed_walk)] != '1')
		cam->pos_x -= cam->plane_x * mv->speed_walk;
	if (map->map[(int)floor(cam->pos_y - cam->plane_y * mv->speed_walk)]
				[(int)floor(cam->pos_x)] != '1')
		cam->pos_y -= cam->plane_y * mv->speed_walk;
}

void	mv_lat_right(t_cam *cam, t_mv *mv, t_map *map)
{
	if (map->map[(int)floor(cam->pos_y)]
				[(int)floor(cam->pos_x + cam->plane_x * mv->speed_walk)] != '1')
		cam->pos_x += cam->plane_x * mv->speed_walk;
	if (map->map[(int)floor(cam->pos_y + cam->plane_y * mv->speed_walk)]
				[(int)floor(cam->pos_x)] != '1')
		cam->pos_y += cam->plane_y * mv->speed_walk;
}

void	mv_up(t_cam *cam, t_mv *mv, t_map *map)
{
	if (map->map[(int)(cam->pos_y)]
				[(int)(cam->pos_x + cam->dir_x * mv->speed_walk)] != '1')
		cam->pos_x += cam->dir_x * mv->speed_walk;
	if (map->map[(int)(cam->pos_y + cam->dir_y * mv->speed_walk)]
				[(int)(cam->pos_x)] != '1')
		cam->pos_y += cam->dir_y * mv->speed_walk;
}

void	mv_down(t_cam *cam, t_mv *mv, t_map *map)
{
	if (map->map[(int)cam->pos_y]
				[(int)(cam->pos_x - cam->dir_x * mv->speed_walk)] != '1')
		cam->pos_x -= cam->dir_x * mv->speed_walk;
	if (map->map[(int)(cam->pos_y - cam->dir_y * mv->speed_walk)]
				[(int)cam->pos_x] != '1')
		cam->pos_y -= cam->dir_y * mv->speed_walk;
}
