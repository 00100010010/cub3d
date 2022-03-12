/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <jtrebes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:14:43 by jtrebes           #+#    #+#             */
/*   Updated: 2020/11/05 15:26:29 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				main_loop(t_c *c)
{
	if (c->key.total)
		moving_engine(c);
	casting_engine(c);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.ptr, 0, 0);
	return (0);
}

void			init(t_c *c, int ac, char **av)
{
	ft_bzero(c, sizeof(t_c));
	if (ac == 3 && !ft_strncmp(av[2], "--save", 6))
		c->screenshot = 1;
	init_cub_file(c, ac, av);
	init_cam_axe(c);
	init_image(c);
	moving_engine(c);
	casting_engine(c);
	if (c->screenshot)
		make_screenshot(c);
	init_window(c);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img.ptr, 0, 0);
}

int				main(int ac, char **av)
{
	t_c	c;

	init(&c, ac, av);
	mlx_hook(c.win_ptr, X_EVENT_KEY_PRESS, 0x1, keyboard_input, &c);
	mlx_hook(c.win_ptr, X_EVENT_KEY_RELEASE, 0x2, keyboard_release, &c);
	mlx_hook(c.win_ptr, X_EVENT_KEY_EXIT, 1L << 17, ft_close, &c);
	mlx_loop_hook(c.mlx_ptr, &main_loop, &c);
	mlx_loop(c.mlx_ptr);
	return (EXIT_SUCCESS);
}
