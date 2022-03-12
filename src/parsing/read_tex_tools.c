/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tex_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:07:55 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/06 09:08:40 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			check_txtrs(t_c *c)
{
	if ((c->txtrs.sky.name || c->txtrs.sky.rgb_flag)
	&& (c->txtrs.floor.name || c->txtrs.floor.rgb_flag)
	&& c->txtrs.wall_no.name && c->txtrs.wall_so.name
	&& c->txtrs.wall_we.name && c->txtrs.wall_ea.name
	&& c->txtrs.wall_ea.name && c->txtrs.sprt.name)
		c->check.txtrs = 1;
}

void			emergency_exit_txtrs(t_c *c, char *str1, int code)
{
	if (str1)
		free(str1);
	ft_check_error(code, c);
}

int				pick_line_color(t_tex *tex, char *line, int k)
{
	int		x;

	if (!tex->rgb[0] && !tex->rgb_flag)
		x = 0;
	else if (!tex->rgb[1] && tex->rgb_flag == 1)
		x = 1;
	else if (!tex->rgb[2] && tex->rgb_flag == 2)
		x = 2;
	else
		return (0);
	if (ft_isdigit(line[k]))
		tex->rgb[x] = ft_atoi(&line[k]);
	else
		return (0);
	if (tex->rgb[x] > 255 || tex->rgb[x] < 0)
		return (0);
	tex->rgb_flag = x + 1;
	return (1);
}

int				put_rgb(t_c *c, t_tex *tex, char *line)
{
	int		k;

	k = 0;
	while (line[k] && ft_isspace(line[k]))
		k++;
	while (line[k] && tex->rgb_flag <= 2)
	{
		while (line[k] && ft_isspace(line[k]))
			k++;
		if (!pick_line_color(tex, line, k))
			return (0);
		while (line[k] && ft_isdigit(line[k]))
			k++;
		while (line[k] && ft_isspace(line[k]))
			k++;
		if (tex->rgb_flag != 3 && line[k] == ',' && line[k + 1])
			++k;
		else if (tex->rgb_flag == 3 && !line[k])
			return (1);
		else
			return (0);
	}
	if (line[k] || tex->rgb_flag != 3)
		return (0);
	return (1);
}

void			read_tex_name(char *line, t_tex *tx, int k)
{
	int		i;

	while (line[k] && ft_isspace(line[k]))
		k++;
	i = k;
	while (line[k])
		k++;
	tx->leak = 1;
	k--;
	while (ft_isspace(line[k]))
		k--;
	k++;
	tx->name = ft_substr(line, i, k - i);
}
