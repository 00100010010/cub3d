/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:07:09 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/08 12:16:20 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			read_file(t_c *c)
{
	int		i;
	int		y;

	y = 0;
	while (y <= c->cubfile_y && !c->check.map)
	{
		i = 0;
		if (c->check.res && c->check.txtrs && c->cubfile[y][i])
			read_map(c->cubfile, c, y);
		if ((c->cubfile[y][i] == '1' || c->cubfile[y][i] == '0')
		&& (!c->check.res || !c->check.txtrs))
			ft_check_error(30, c);
		while (c->cubfile[y][i] != '\0' && ft_isspace(c->cubfile[y][i]))
			i++;
		if (!c->check.map && c->cubfile[y][i] == 'R')
			read_res(c->cubfile[y], c, i);
		else if (!c->check.map && (c->cubfile[y][i] == 'N'
		|| c->cubfile[y][i] == 'S' || c->cubfile[y][i] == 'W'
		|| c->cubfile[y][i] == 'E' || c->cubfile[y][i] == 'F'
		|| c->cubfile[y][i] == 'C'))
			read_tex(c->cubfile[y], c, i);
		y++;
	}
}

void			check_argv(t_c *c, int ac, char **av)
{
	int		i;

	if (ac < 2 || ac > 3 || (ac == 3 && ft_strncmp(av[2], "--save", 6)))
		ft_check_error(1, c);
	if ((open(av[1], O_DIRECTORY) != -1)
	|| ((c->fd = open(av[1], O_RDONLY)) == -1))
		ft_check_error(2, c);
	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 4] != '.'
	|| av[1][i - 3] != 'c'
	|| av[1][i - 2] != 'u'
	|| av[1][i - 1] != 'b')
		ft_check_error(3, c);
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

int				init_cub_file(t_c *c, int ac, char **av)
{
	int		i;

	check_argv(c, ac, av);
	init_mlx(c);
	init_tx_tab(c);
	c->cubfile = make_tab_from_file(c->fd, c);
	read_file(c);
	if (!c->check.res)
		ft_check_error(10, c);
	if (!c->check.txtrs)
		ft_check_error(20, c);
	if (!c->cam.pos_x)
		ft_check_error(35, c);
	check_depth_search(c);
	init_txtrs(c);
	init_sprts(c);
	close(c->fd);
	return (0);
}
