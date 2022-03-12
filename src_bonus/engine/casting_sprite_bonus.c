/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:33:40 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 12:24:19 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				change_order_sprts(t_sprt *sprt, int i)
{
	double	dist_tmp;
	double	x_tmp;
	double	y_tmp;
	char	type_tmp;

	dist_tmp = sprt->sprts[i + 1].dist;
	sprt->sprts[i + 1].dist = sprt->sprts[i].dist;
	sprt->sprts[i].dist = dist_tmp;
	x_tmp = sprt->sprts[i + 1].x;
	y_tmp = sprt->sprts[i + 1].y;
	type_tmp = sprt->sprts[i + 1].type;
	sprt->sprts[i + 1].x = sprt->sprts[i].x;
	sprt->sprts[i + 1].y = sprt->sprts[i].y;
	sprt->sprts[i + 1].type = sprt->sprts[i].type;
	sprt->sprts[i].x = x_tmp;
	sprt->sprts[i].y = y_tmp;
	sprt->sprts[i].type = type_tmp;
	return (0);
}

void			sort_sprts(t_cam *cam, t_sprt *sprt)
{
	int	i;

	i = -1;
	while (++i < sprt->amount)
	{
		sprt->sprts[i].dist = ((cam->pos_x - sprt->sprts[i].x) *
			(cam->pos_x - sprt->sprts[i].x) + (cam->pos_y -
			sprt->sprts[i].y) * (cam->pos_y - sprt->sprts[i].y));
	}
	i = 0;
	while (i < sprt->amount - 1)
	{
		if (sprt->sprts[i].dist < sprt->sprts[i + 1].dist)
			i = change_order_sprts(sprt, i);
		else
			i++;
	}
}

void			sprt3(t_sprt *sprt)
{
	sprt->start_y = -sprt->h / 2 + sprt->res_h / 2 + sprt->vmovscrn;
	if (sprt->start_y < 0)
		sprt->start_y = 0;
	sprt->drawend_y = sprt->h / 2 + sprt->res_h / 2 + sprt->vmovscrn;
	if (sprt->drawend_y >= sprt->res_h)
		sprt->drawend_y = sprt->res_h - 1;
	sprt->w = abs((int)(sprt->res_h / (sprt->trsnfrm_y))) / UDIV;
	sprt->start_x = -sprt->w / 2 + sprt->scrnx;
	if (sprt->start_x < 0)
		sprt->start_x = 0;
	sprt->drawend_x = sprt->w / 2 + sprt->scrnx;
	if (sprt->drawend_x >= sprt->res_w)
		sprt->drawend_x = sprt->res_w - 1;
}

void			sprt2(t_sprt *sprt, t_cam *cam, int i)
{
	sprt->x = sprt->sprts[i].x - cam->pos_x + 0.5;
	sprt->y = sprt->sprts[i].y - cam->pos_y + 0.5;
	sprt->iv_dt = 1.0 / (cam->plane_x * cam->dir_y - cam->dir_x * cam->plane_y);
	sprt->trsnfrm_x = sprt->iv_dt * (cam->dir_y * sprt->x - cam->dir_x
																* sprt->y);
	sprt->trsnfrm_y = sprt->iv_dt * (-cam->plane_y * sprt->x + cam->plane_x
																* sprt->y);
	sprt->scrnx = (int)((sprt->res_w / 2) * (1 + sprt->trsnfrm_x
														/ sprt->trsnfrm_y));
	sprt->vmovscrn = (int)(VMOVE / sprt->trsnfrm_y);
	sprt->h = abs((int)(sprt->res_h / (sprt->trsnfrm_y))) / VDIV;
}

void			sprt_casting(t_c *c)
{
	int		i;

	sort_sprts(&c->cam, &c->sprt);
	i = 0;
	while (i < c->sprt.amount)
	{
		sprt2(&c->sprt, &c->cam, i);
		sprt3(&c->sprt);
		sprt4(&c->sprt, &c->txtrs, i, c);
		i++;
	}
	c->ray.sprt = 0;
}
