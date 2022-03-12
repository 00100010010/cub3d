/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:25:07 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/08 11:41:33 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	casting_engine(t_c *c)
{
	int	x;

	x = 0;
	while (x < c->map.res_x)
	{
		pose_base(&c->ray, c->map.res_x, &c->cam, x);
		wall_casting(c, x);
		floor_casting(c, x);
		c->sprt.zbuffer[x] = c->ray.prpwalldist;
		x++;
	}
	if (c->ray.sprt)
		sprt_casting(c);
}
