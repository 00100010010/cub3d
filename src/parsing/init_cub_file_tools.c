/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_file_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:07:09 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/08 09:15:51 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			init_sprts(t_c *c)
{
	double		*zbuffer_cpy;

	if (!(zbuffer_cpy = malloc(sizeof(double) * c->map.res_x)))
		ft_check_error(31, c);
	c->check.zbuffer = 1;
	c->sprt.zbuffer = zbuffer_cpy;
}

char			**tab_transfer(char **tab, char *str, int vlen, t_c *c)
{
	char		**res;
	int			i;

	if (!str)
		return (tab);
	if (!(res = malloc(sizeof(char *) * (vlen + 1))))
		return (0);
	i = 0;
	while (i < vlen)
	{
		res[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	if (vlen)
		free(tab);
	res[vlen] = ft_strdup(str);
	c->cubfile_y = vlen;
	return (res);
}

void			emergency_free_res(int i, char **str1, char *str2)
{
	if (i)
	{
		while (--i >= 0)
			free(str1[i]);
		free(str1);
	}
	if (str2)
		free(str2);
}

char			**make_tab_from_file2(t_c *c, char **res, int i, char *line)
{
	if (!(res = tab_transfer(res, line, i, c)))
	{
		emergency_free_res(i, res, line);
		ft_check_error(5, c);
	}
	free(line);
	return (res);
}

char			**make_tab_from_file(int fd, t_c *c)
{
	char		**res;
	int			i;
	char		*line;
	int			gnl;

	i = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		res = make_tab_from_file2(c, res, i, line);
		i++;
	}
	if (gnl == -1 || (!(res = tab_transfer(res, line, i, c))))
	{
		if (gnl == -1)
			emergency_free_res(i, res, 0);
		else
			emergency_free_res(i, res, line);
		ft_check_error(5, c);
	}
	if (line)
		free(line);
	c->check.cubfile = 1;
	return (res);
}
