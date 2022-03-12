/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:33:40 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 12:26:38 by jtrebes          ###   ########.fr       */
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

void			sprt5(t_sprt *sprt, t_txtrs *txtrs, int stripe, t_c *c)
{
	int		y;
	int		z;
	int		d;
	int		color;

	y = sprt->start_y - 1;
	z = sprt->drawend_y + sprt->h + sprt->h / 3;
	while (++y < sprt->drawend_y)
	{
		d = (y - sprt->vmovscrn) * 2 - sprt->res_h + sprt->h;
		txtrs->sprt.y = ((d * txtrs->sprt.h) / sprt->h) / 2;
		if (txtrs->sprt.y < 0)
			txtrs->sprt.y = 0;
		color = txtrs->sprt.addr[(int)(txtrs->sprt.y * txtrs->sprt.w
														+ txtrs->sprt.x)];
		c->img.addr[(int)(y * sprt->res_w + stripe)] = color;
		z--;
	}
}

void			sprt4(t_sprt *sprt, t_txtrs *txtrs, int i, t_c *c)
{
	int		stripe;

	stripe = sprt->start_x;
	while (stripe < sprt->drawend_x)
	{
		txtrs->sprt.x = (int)(2 * (stripe - (-sprt->w / 2 + sprt->scrnx))
												* txtrs->sprt.w / sprt->w) / 2;
		if (sprt->trsnfrm_y > 0
		&& stripe > 0
		&& stripe < sprt->res_w
		&& sprt->trsnfrm_y < sprt->zbuffer[stripe])
			sprt5(sprt, txtrs, stripe, c);
		stripe++;
	}
}
