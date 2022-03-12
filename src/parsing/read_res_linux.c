/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_res_linux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:51:42 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/05 17:18:00 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			ft_atoi_res(const char *str, t_c *c)
{
	long		res;

	while (!c->map.res_x || !c->map.res_y)
	{
		res = 0;
		while (ft_isspace(*str))
			str++;
		if (!ft_isdigit(*str))
			ft_check_error(16, c);
		while (*str <= '9' && *str >= '0')
		{
			res = res * 10 + *str - '0';
			str++;
		}
		if (res > 3000)
			res = 3000;
		if (!c->map.res_x)
			c->map.res_x = res;
		else
			c->map.res_y = res;
	}
}

void			adapt_res(t_c *c)
{
	int		w;
	int		h;

	if (!c->screenshot)
	{
		mlx_get_screen_size(c->mlx_ptr, &w, &h);
		c->map.res_x = (c->map.res_x < w ? c->map.res_x : w);
		c->map.res_y = (c->map.res_y < h ? c->map.res_y : h);
	}
	c->sprt.res_h = c->map.res_y;
	c->sprt.res_w = c->map.res_x;
	c->check.res = 1;
}

int				read_res(char *line, t_c *c, int i)
{
	if (c->check.res)
		ft_check_error(14, c);
	while (ft_isspace(line[0]))
		line++;
	ft_atoi_res(++line, c);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != '\n' && !ft_isspace(*line))
			ft_check_error(13, c);
		line++;
	}
	adapt_res(c);
	if (c->map.res_x <= 0 || c->map.res_y <= 0)
		ft_check_error(12, c);
	return (1);
}
