/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:33:40 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 09:45:50 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		add_sprt_data(t_c *c, int y, int x, int type)
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

void		sprt3(t_sprt *sprt)
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

void		sprt2(t_sprt *sprt, t_cam *cam, int i)
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

void		sprt_casting(t_c *c)
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
