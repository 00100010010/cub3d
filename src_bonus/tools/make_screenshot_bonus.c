/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:42:06 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/04 12:05:22 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_header(t_c *c)
{
	c->screen.filesize = c->map.res_y * c->map.res_x * 4 + 54;
	c->screen.offset = 54;
	c->screen.headersize = 40;
	c->screen.image_width = c->map.res_x;
	c->screen.image_height = c->map.res_y;
	c->screen.plane = 1;
	c->screen.bpp = c->img.bpp;
	c->screen.total_size = c->map.res_y * c->map.res_x * 4;
}

int		make_screenshot(t_c *c)
{
	int				fd;
	int				i;
	const void		*buffer;

	if (!(fd = open("screenshot.bmp",
								O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664)))
		ft_check_error(6, c);
	buffer = mlx_get_data_addr(c->img.ptr, &(c->img.bpp), &(c->img.size_l),
															&(c->img.endian));
	ft_bzero(&c->screen, sizeof(t_screen));
	init_header(c);
	write(fd, "BM", 2);
	write(fd, &c->screen, sizeof(t_screen));
	i = 0;
	while (i < c->map.res_y)
	{
		if (write(fd, &buffer[(c->map.res_y - i++ - 1) * c->img.size_l],
												c->img.size_l) != c->img.size_l)
			ft_check_error(6, c);
	}
	if (close(fd) == -1)
		ft_check_error(6, c);
	ft_close(c);
	return (1);
}
