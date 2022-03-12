/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_res_osx_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:50:37 by jim               #+#    #+#             */
/*   Updated: 2020/11/06 09:09:23 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_atoi_res(const char *str, t_c *c)
{
	long	res;

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
		if (res > 1920)
			res = 1920;
		if (res == 1920 && c->map.res_x)
			res = 1080;
		if (!c->map.res_x)
			c->map.res_x = res;
		else
			c->map.res_y = res;
	}
}

int			read_res(char *line, t_c *c, int i)
{
	if (c->check.res)
		ft_check_error(14, c);
	while (ft_isspace(line[0]))
		line++;
	ft_atoi_res(++line, c);
	while (*line)
	{
		if (!ft_isdigit(*line) && !ft_isspace(*line) && *line != '\n')
			ft_check_error(13, c);
		line++;
	}
	if (c->map.res_x <= 0 || c->map.res_y <= 0)
		ft_check_error(12, c);
	c->sprt.res_h = c->map.res_y;
	c->sprt.res_w = c->map.res_x;
	c->check.res = 1;
	return (1);
}
