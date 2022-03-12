/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:56:09 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 12:21:54 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				rgb(int r, int g, int b)
{
	return ((r * pow(256, 2)) + (g * 256) + b);
}

void			weapon_casting(t_c *c, t_tex *tex)
{
	double	x;
	double	y;
	int		color;

	x = 0;
	while (x < c->map.res_x)
	{
		tex->x = (int)(tex->w / (c->map.res_x / x));
		y = 0;
		while (y < c->map.res_y)
		{
			tex->y = (int)(tex->h / (c->map.res_y / y));
			color = tex->addr[(int)(tex->y * tex->w + tex->x)];
			if (color && color != -16777216)
				c->img.addr[(int)(y * c->map.res_x + x)] = color;
			y++;
		}
		x++;
	}
}

double			take_boussole(t_c *c)
{
	double		boussole;

	boussole = 0;
	if (c->cam.dir_x > 0)
	{
		if (c->cam.dir_y <= 0)
			boussole = (c->cam.dir_y * -1) * 24;
		else if (c->cam.dir_y > 0)
			boussole = (c->cam.dir_x * 24) + 75;
	}
	else
	{
		if (c->cam.dir_y >= 0)
			boussole = (c->cam.dir_y * 25) + 50;
		else if (c->cam.dir_y < 0)
			boussole = ((c->cam.dir_y + 1) * 24) + 25;
	}
	return (boussole / 100);
}

void			fullsky_casting(t_c *c, t_tex *tex)
{
	double		x;
	double		y;
	int			color;
	double		boussole;

	boussole = take_boussole(c);
	x = 0;
	while (x < c->map.res_x)
	{
		tex->x = (tex->w / (c->map.res_x / x));
		tex->x += tex->w * boussole;
		if (tex->x >= tex->w)
			tex->x -= tex->w;
		y = 0;
		while (y < c->map.res_y / 2)
		{
			tex->y = (int)(tex->h / (c->map.res_y / y));
			color = tex->addr[(int)(tex->y * tex->w + tex->x)];
			c->img.addr[(int)(y * c->map.res_x + x)] = color;
			y++;
		}
		x++;
	}
}

void			add_sprt_data(t_c *c, int y, int x, int type)
{
	t_sprts		*sprts_new;
	int			i;

	c->sprt.amount++;
	if (!(sprts_new = malloc(sizeof(t_sprts) * c->sprt.amount)))
		ft_check_error(31, c);
	i = 0;
	while (i < c->sprt.amount - 1)
	{
		sprts_new[i] = c->sprt.sprts[i];
		i++;
	}
	sprts_new[i].y = y;
	sprts_new[i].x = x;
	sprts_new[i].type = type;
	if (i)
		free(c->sprt.sprts);
	c->sprt.sprts = sprts_new;
	c->check.sprts = 1;
}
