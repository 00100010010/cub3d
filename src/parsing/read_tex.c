/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:07:55 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/06 09:08:47 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			read_cub_file_color(char *id, char *line, t_c *c, int k)
{
	while (line[k] && ft_isspace(line[k]))
		k++;
	if (ft_isdigit(line[k]))
	{
		if (!ft_strncmp(id, "C", 1))
		{
			if (!put_rgb(c, &c->txtrs.sky, &line[k]))
				emergency_exit_txtrs(c, id, 24);
		}
		else if (!ft_strncmp(id, "F", 1))
		{
			if (!put_rgb(c, &c->txtrs.floor, &line[k]))
				emergency_exit_txtrs(c, id, 24);
		}
	}
	else
		emergency_exit_txtrs(c, id, 23);
}

void			read_tex_id(t_c *c, char *line, char *id, int k)
{
	if (!ft_strncmp(id, "NO", 2) && !c->txtrs.wall_no.name)
		read_tex_name(line, &c->txtrs.wall_no, k);
	else if (!ft_strncmp(id, "SO", 2) && !c->txtrs.wall_so.name)
		read_tex_name(line, &c->txtrs.wall_so, k);
	else if (!ft_strncmp(id, "WE", 2) && !c->txtrs.wall_we.name)
		read_tex_name(line, &c->txtrs.wall_we, k);
	else if (!ft_strncmp(id, "EA", 2) && !c->txtrs.wall_ea.name)
		read_tex_name(line, &c->txtrs.wall_ea, k);
	else if (!ft_strncmp(id, "S", 1) && !c->txtrs.sprt.name)
		read_tex_name(line, &c->txtrs.sprt, k);
	else if ((!ft_strncmp(id, "C", 1)
	&& !c->txtrs.sky.rgb_flag && !c->txtrs.sky.name)
	|| (!ft_strncmp(id, "F", 1)
	&& !c->txtrs.floor.rgb_flag && !c->txtrs.floor.name))
		read_cub_file_color(id, line, c, k);
	else
		emergency_exit_txtrs(c, id, 22);
}

void			read_tex(char *line, t_c *c, int i)
{
	char	*id;
	int		k;

	k = i;
	while (line[k] && !ft_isspace(line[k]))
		k++;
	if (k - i < 1 || k - i > 2)
		ft_check_error(21, c);
	id = ft_substr(line, i, k - i);
	read_tex_id(c, line, id, k);
	free(id);
	check_txtrs(c);
}
