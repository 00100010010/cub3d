/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:56:09 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 12:17:11 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				rgb(int r, int g, int b)
{
	return ((r * pow(256, 2)) + (g * 256) + b);
}

char			**reverse_map(t_c *c, int y, int i, char **map_file)
{
	int		z;
	int		y_cpy;
	char	*cpy;

	y_cpy = y;
	z = c->cubfile_y;
	while (y < z)
	{
		cpy = ft_strdup(map_file[y]);
		free(map_file[y]);
		map_file[y] = ft_strdup(map_file[z]);
		free(map_file[z]);
		map_file[z] = ft_strdup(cpy);
		free(cpy);
		y++;
		z--;
	}
	return (map_file);
}
