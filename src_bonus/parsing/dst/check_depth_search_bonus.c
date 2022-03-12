/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_depth_search_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:19:30 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/07 13:31:04 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void			emergency_free_maper(t_c *c, int i)
{
	int		flag;

	flag = i;
	if (flag)
	{
		while (--i >= 0)
			free(c->maper.memory[i]);
		free(c->maper.memory);
		c->check.maper = 0;
	}
	if (c->check.tracks)
		free(c->maper.tracks);
	c->check.tracks = 0;
	ft_check_error(34, c);
}

void			init_maper(t_c *c)
{
	int		i;

	c->maper.y_max = c->map.y_cpy;
	c->maper.x = c->cam.pos_x - 0.5;
	c->maper.y = c->cam.pos_y - 0.5;
	c->check.maper = 1;
	if (!(c->maper.memory = (malloc(sizeof(char *) * (c->maper.y_max + 1)))))
		ft_check_error(34, c);
	i = 0;
	while (i <= c->maper.y_max)
	{
		if (!(c->maper.memory[i] = ft_strdup(c->map.map[i])))
			emergency_free_maper(c, i);
		i++;
	}
	c->maper.memory[c->maper.y][c->maper.x] = '2';
	c->maper.last_track = 0;
	save_checkpoint(c);
}

void			maper_mv_2(t_c *c)
{
	if (c->maper.y >= 1
	&& c->maper.memory[c->maper.y - 1][c->maper.x + 1] != '\0'
	&& c->maper.memory[c->maper.y - 1][c->maper.x + 1] != '1')
	{
		c->maper.y--;
		c->maper.x++;
	}
	else if (c->maper.x >= 1
	&& c->maper.memory[c->maper.y + 1][c->maper.x - 1] != '\0'
	&& c->maper.memory[c->maper.y + 1][c->maper.x - 1] != '1')
	{
		c->maper.y++;
		c->maper.x--;
	}
	else if (c->maper.y >= 1 && c->maper.x >= 1
	&& c->maper.memory[c->maper.y - 1][c->maper.x - 1] != '\0'
	&& c->maper.memory[c->maper.y - 1][c->maper.x - 1] != '1')
	{
		c->maper.y--;
		c->maper.x--;
	}
}

void			maper_mv(t_c *c)
{
	if (c->maper.x >= 1 && c->maper.memory[c->maper.y][c->maper.x - 1] != '1')
		c->maper.x--;
	else if (c->maper.y >= 1 && c->maper.memory[c->maper.y - 1][c->maper.x]
	&& c->maper.memory[c->maper.y - 1][c->maper.x] != '1')
		c->maper.y--;
	else if (c->maper.memory[c->maper.y][c->maper.x + 1] != '\0'
	&& c->maper.memory[c->maper.y][c->maper.x + 1] != '1')
		c->maper.x++;
	else if (c->maper.y + 1 <= c->maper.y_max
	&& c->maper.memory[c->maper.y + 1][c->maper.x]
	&& c->maper.memory[c->maper.y + 1][c->maper.x] != '1')
		c->maper.y++;
	else if (c->maper.memory[c->maper.y + 1][c->maper.x + 1] != '\0'
	&& c->maper.memory[c->maper.y + 1][c->maper.x + 1] != '1')
	{
		c->maper.y++;
		c->maper.x++;
	}
	else
		maper_mv_2(c);
	if (c->maper.memory[c->maper.y][c->maper.x] == '1')
		return ;
	else if (c->maper.memory[c->maper.y][c->maper.x] == '3')
		ft_check_error(33, c);
	c->maper.memory[c->maper.y][c->maper.x] = '1';
}

void			check_depth_search(t_c *c)
{
	int				flag;
	int				i;

	init_maper(c);
	put_map_limits(c);
	maper_mv(c);
	while (c->maper.last_track > 0 && (c->maper.y || c->maper.x))
	{
		while (maper_count_ways(c))
			maper_mv(c);
		if (!maper_count_ways(c) && c->maper.last_track > 0)
			maper_back_track(c);
	}
	i = -1;
	while (++i <= c->maper.y_max)
		free(c->maper.memory[i]);
	free(c->maper.memory);
	if (c->check.tracks)
		free(c->maper.tracks);
	c->check.maper = 0;
	c->check.tracks = 0;
}
