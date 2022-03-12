/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite_tools_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:33:40 by jim               #+#    #+#             */
/*   Updated: 2020/11/07 11:47:58 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			set_reflect_2(t_c *c, int stripe, int color)
{
	double		maths;

	maths = c->sprt.r_z * c->sprt.res_w + stripe;
	c->txtrs.sprt.rgb[0] = (color >> 16) & 0xFF;
	c->txtrs.sprt.rgb[1] = (color >> 8) & 0xFF;
	c->txtrs.sprt.rgb[2] = color & 0xFF;
	c->txtrs.sprt.rgb[0] += (c->img.addr[(int)maths] >> 16) & 0xFF;
	c->txtrs.sprt.rgb[0] += (c->img.addr[(int)maths] >> 16) & 0xFF;
	c->txtrs.sprt.rgb[1] += (c->img.addr[(int)maths] >> 8) & 0xFF;
	c->txtrs.sprt.rgb[1] += (c->img.addr[(int)maths] >> 8) & 0xFF;
	c->txtrs.sprt.rgb[2] += c->img.addr[(int)maths] & 0xFF;
	c->txtrs.sprt.rgb[2] += c->img.addr[(int)maths] & 0xFF;
	c->img.addr[(int)maths] = rgb(c->txtrs.sprt.
				rgb[0] / 3, c->txtrs.sprt.rgb[1] / 3, c->txtrs.sprt.rgb[2] / 3);
}

void			set_reflect(t_c *c, int stripe, int color)
{
	double		maths;

	maths = c->sprt.r_y * c->sprt.res_w + stripe;
	c->txtrs.sprt.rgb[0] = (color >> 16) & 0xFF;
	c->txtrs.sprt.rgb[1] = (color >> 8) & 0xFF;
	c->txtrs.sprt.rgb[2] = color & 0xFF;
	c->txtrs.sprt.rgb[0] += (c->img.addr[(int)maths] >> 16) & 0xFF;
	c->txtrs.sprt.rgb[1] += (c->img.addr[(int)maths] >> 8) & 0xFF;
	c->txtrs.sprt.rgb[2] += c->img.addr[(int)maths] & 0xFF;
	c->img.addr[(int)maths] = rgb(c->txtrs.sprt.rgb[0] / 2,
							c->txtrs.sprt.rgb[1] / 2, c->txtrs.sprt.rgb[2] / 2);
	if (c->sprt.r_z >= c->sprt.res_h - 1)
		return ;
	set_reflect_2(c, stripe, color);
}

void			sprt5_b(t_sprt *sprt, t_txtrs *txtrs, int stripe, t_c *c)
{
	int		d;
	int		color;

	sprt->r_y = sprt->start_y - 1;
	sprt->r_z = sprt->drawend_y + sprt->h + sprt->h / 3;
	while (++sprt->r_y < sprt->drawend_y)
	{
		d = (sprt->r_y - sprt->vmovscrn) * 2 - sprt->res_h + sprt->h;
		txtrs->sprt.y = ((d * txtrs->sprt.h) / sprt->h) / 2;
		color = txtrs->sprt2.addr[(int)(txtrs->sprt.y * txtrs->sprt.w
														+ txtrs->sprt.x)];
		if (color && color != 16777215)
			set_reflect(c, stripe, color);
		sprt->r_z--;
	}
}

void			sprt5(t_sprt *sprt, t_txtrs *txtrs, int stripe, t_c *c)
{
	int		d;
	int		color;

	sprt->r_y = sprt->start_y - 1;
	sprt->r_z = sprt->drawend_y + sprt->h + sprt->h / 3;
	while (++sprt->r_y < sprt->drawend_y)
	{
		d = (sprt->r_y - sprt->vmovscrn) * 2 - sprt->res_h + sprt->h;
		txtrs->sprt.y = ((d * txtrs->sprt.h) / sprt->h) / 2;
		if (txtrs->sprt.y < 0)
			txtrs->sprt.y = 0;
		color = txtrs->sprt.addr[(int)(txtrs->sprt.y * txtrs->sprt.w
														+ txtrs->sprt.x)];
		if (color && color != 16777215)
			set_reflect(c, stripe, color);
		sprt->r_z--;
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
		&& sprt->trsnfrm_y < sprt->zbuffer[stripe] && sprt->sprts[i].type == 0)
			sprt5(sprt, txtrs, stripe, c);
		else if (sprt->trsnfrm_y > 0
		&& stripe > 0
		&& stripe < sprt->res_w
		&& sprt->trsnfrm_y < sprt->zbuffer[stripe] && sprt->sprts[i].type == 1)
			sprt5_b(sprt, txtrs, stripe, c);
		stripe++;
	}
}
