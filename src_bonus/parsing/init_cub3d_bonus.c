/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:35:28 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/03 21:14:20 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_cam_axe(t_c *c)
{
	if (c->cam.axe == 'N')
	{
		c->cam.dir_y++;
		c->cam.plane_x++;
	}
	else if (c->cam.axe == 'S')
	{
		c->cam.dir_y--;
		c->cam.plane_x--;
	}
	else if (c->cam.axe == 'W')
	{
		c->cam.dir_x--;
		c->cam.plane_y++;
	}
	else if (c->cam.axe == 'E')
	{
		c->cam.dir_x++;
		c->cam.plane_y--;
	}
}

void	init_mlx(t_c *c)
{
	c->mlx_ptr = mlx_init();
	c->check.mlx_init = 1;
}

void	init_window(t_c *c)
{
	c->win_ptr = mlx_new_window(c->mlx_ptr, c->map.res_x,
												c->map.res_y, WIN_TITLE);
	c->check.mlx_win = 1;
}

void	init_image(t_c *c)
{
	c->img.ptr = mlx_new_image(c->mlx_ptr, c->map.res_x,
									c->map.res_y);
	c->img.addr =
	(unsigned int *)mlx_get_data_addr(c->img.ptr,
					&c->img.bpp, &c->img.size_l, &c->img.endian);
	c->check.mlx_img = 1;
}
