/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_depth_search_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:31:43 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 11:40:53 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void		put_map_limits(t_c *c)
{
	int		i;
	int		k;
	char	*cpy;

	i = 1;
	while (i < c->map.y_cpy)
	{
		k = c->map.len_secu - ft_strlen(c->maper.memory[i]);
		while (k > 0)
		{
			if (!(cpy = ft_strdup(c->maper.memory[i])))
				ft_check_error(34, c);
			free(c->maper.memory[i]);
			if (!(c->maper.memory[i] = ft_strjoin(cpy, "3")))
			{
				free(cpy);
				ft_check_error(34, c);
			}
			free(cpy);
			k--;
		}
		i++;
	}
}

void		save_checkpoint(t_c *c)
{
	t_tracks		*tracks_cpy;
	int				i;

	c->check.tracks = 1;
	if (!(tracks_cpy = malloc(sizeof(t_tracks) * ++c->maper.last_track)))
		ft_check_error(31, c);
	i = 0;
	while (i < c->maper.last_track - 1)
	{
		tracks_cpy[i] = c->maper.tracks[i];
		i++;
	}
	if (i)
		free(c->maper.tracks);
	tracks_cpy[i].x = c->maper.x;
	tracks_cpy[i].y = c->maper.y;
	c->maper.tracks = tracks_cpy;
}

int			maper_count_ways2(t_c *c)
{
	int		i;

	i = 0;
	if (c->maper.memory[c->maper.y + 1][c->maper.x + 1] != '\0'
	&& c->maper.memory[c->maper.y + 1][c->maper.x + 1] != '1')
		i++;
	if (c->maper.y >= 1
	&& c->maper.memory[c->maper.y - 1][c->maper.x + 1] != '\0'
	&& c->maper.memory[c->maper.y - 1][c->maper.x + 1] != '1')
		i++;
	if (c->maper.x >= 1
	&& c->maper.memory[c->maper.y + 1][c->maper.x - 1] != '\0'
	&& c->maper.memory[c->maper.y + 1][c->maper.x - 1] != '1')
		i++;
	if (c->maper.y >= 1 && c->maper.x >= 1
	&& c->maper.memory[c->maper.y - 1][c->maper.x - 1] != '\0'
	&& c->maper.memory[c->maper.y - 1][c->maper.x - 1] != '1')
		i++;
	return (i);
}

int			maper_count_ways(t_c *c)
{
	int		i;

	i = 0;
	if (c->maper.x >= 1 && c->maper.memory[c->maper.y][c->maper.x - 1] != '1')
		i++;
	if (c->maper.y >= 1 && c->maper.memory[c->maper.y - 1][c->maper.x]
	&& c->maper.memory[c->maper.y - 1][c->maper.x] != '1')
		i++;
	if (c->maper.memory[c->maper.y][c->maper.x + 1] != '\0'
	&& c->maper.memory[c->maper.y][c->maper.x + 1] != '1')
		i++;
	if (c->maper.y + 1 <= c->maper.y_max
	&& c->maper.memory[c->maper.y + 1][c->maper.x]
	&& c->maper.memory[c->maper.y + 1][c->maper.x] != '1')
		i++;
	i += maper_count_ways2(c);
	if (i > 1)
		save_checkpoint(c);
	return (i);
}

void		maper_back_track(t_c *c)
{
	c->maper.x = c->maper.tracks[c->maper.last_track - 1].x;
	c->maper.y = c->maper.tracks[c->maper.last_track - 1].y;
	c->maper.last_track--;
}
