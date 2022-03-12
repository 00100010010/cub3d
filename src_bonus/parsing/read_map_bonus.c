/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:52:11 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 12:14:41 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				find_map_start(char **map_file, int z)
{
	int		k;

	while (map_file[z])
	{
		k = -1;
		while (map_file[z][++k])
		{
			if (!ft_isspace(map_file[z][k]))
				return (z);
		}
		z++;
	}
	return (0);
}

char			mark_target(t_c *c, int y, char x)
{
	if (x == '2' || x == '4')
	{
		if (x == '2')
			add_sprt_data(c, c->map.y_cpy, y, 0);
		else
			add_sprt_data(c, c->map.y_cpy, y, 1);
		return ('2');
	}
	else if (x == 'N' || x == 'S' || x == 'W' || x == 'E')
	{
		if (c->cam.pos_x)
			return (0);
		c->cam.pos_x = y + 0.5;
		c->cam.pos_y = c->map.y_cpy + 0.5;
		c->cam.axe = x;
		return ('0');
	}
	else if (x == '1' || x == '0')
		return (x);
	else if (x == ' ')
		return ('3');
	return (0);
}

char			*copy_map(char *map_file, t_c *c)
{
	int		i;
	char	*res;

	i = ft_strlen(map_file) + 2;
	c->map.len_secu = (i > c->map.len_secu ? i : c->map.len_secu);
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	res[0] = '3';
	res[i - 1] = '3';
	res[i] = '\0';
	i = 0;
	while (map_file[i])
	{
		if (!(res[i + 1] = mark_target(c, i + 1, map_file[i])))
		{
			free(res);
			return (0);
		}
		i++;
	}
	return (res);
}

void			emergency_free_map(t_c *c, int error)
{
	c->map.map[0] = ft_strdup("");
	while (--c->map.y_cpy >= 0)
		free(c->map.map[c->map.y_cpy]);
	free(c->map.map);
	c->check.map = 0;
	ft_check_error(error, c);
}

void			read_map(char **map_file, t_c *c, int i)
{
	int		y;
	int		i_cpy;

	i_cpy = i;
	y = find_map_start(map_file, i);
	i = c->cubfile_y - y;
	map_file = reverse_map(c, y, i, map_file);
	y = find_map_start(map_file, i_cpy);
	i = c->cubfile_y - y;
	if (!(c->map.map = malloc(sizeof(char *) * (i + 3))))
		ft_check_error(2, c);
	c->check.map = 1;
	while (++c->map.y_cpy <= i + 1)
	{
		if (!(c->map.map[c->map.y_cpy] = copy_map(map_file
													[c->map.y_cpy + y - 1], c)))
			emergency_free_map(c, 32);
	}
	if (!(c->map.map[0] = malloc(sizeof(char) * (c->map.len_secu + 1))))
		ft_check_error(31, c);
	c->map.map[0][c->map.len_secu] = '\0';
	i = -1;
	while (++i < c->map.len_secu)
		c->map.map[0][i] = '3';
	c->map.map[c->map.y_cpy] = ft_strdup(c->map.map[0]);
}
