/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:47:42 by jim               #+#    #+#             */
/*   Updated: 2020/11/04 23:30:53 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_error4(int n, t_c *c, int fd)
{
	if (n == 20)
		ft_putstr_fd("format error with textures in .cub file", fd);
	if (n == 21)
		ft_putstr_fd(
			"format error with textures in .cub file(.xpm only on Linux)", fd);
	if (n == 22)
		ft_putstr_fd("format error with textures ID in .cub file", fd);
	if (n == 23)
		ft_putstr_fd("format error with floor or sky ID in .cub file", fd);
	if (n == 24)
		ft_putstr_fd("format error with floor or sky ID in .cub file", fd);
	if (n == 25)
		ft_putstr_fd("format error with floor or sky in .cub file", fd);
}

void	ft_check_error3(int n, t_c *c, int fd)
{
	if (n == 30)
		ft_putstr_fd("put Resolution and Textures before the map", fd);
	if (n == 31)
		ft_putstr_fd("malloc error while creating map", fd);
	if (n == 32)
		ft_putstr_fd("invalid character in the map", fd);
	if (n == 33)
		ft_putstr_fd("player is not supposed to have access to void", fd);
	if (n == 34)
		ft_putstr_fd("malloc error while creating map", fd);
	if (n == 35)
		ft_putstr_fd("Player position (N,S,E or W) is missing in the map", fd);
}

void	ft_check_error2(int n, t_c *c, int fd)
{
	if (n == 1)
		ft_putstr_fd("wrong args input [./cub3D] + [map.cub] (+ [--save])", fd);
	if (n == 2)
		ft_putstr_fd("the [map.cub] file failed to open", fd);
	if (n == 3)
		ft_putstr_fd("the [map.cub] file doesnt have \".cub\" extension", fd);
	if (n == 4)
		ft_putstr_fd("error with GetNextLine while reading the .cub file", fd);
	if (n == 5)
		ft_putstr_fd("error while reading the .cub file", fd);
	if (n == 6)
		ft_putstr_fd("error while making screenshot", fd);
	if (n == 10)
		ft_putstr_fd("missing correct Resolution in .cub file", fd);
	if (n == 12)
		ft_putstr_fd("resolution cant be 0 or negative", fd);
	if (n == 13)
		ft_putstr_fd("invalid character in Resolution line", fd);
	if (n == 14)
		ft_putstr_fd("Resolution already definied", fd);
	if (n == 16)
		ft_putstr_fd("resolution contains invalid character", fd);
}

void	ft_check_error(int n, t_c *c)
{
	int			fd;
	int			i;

	fd = 1;
	if (c->check.mlx_init)
		free_all_txtrs(c);
	free_mlx(c);
	free_maps(c);
	if (n)
		ft_putstr_fd("Error\n", fd);
	ft_check_error2(n, c, fd);
	ft_check_error3(n, c, fd);
	ft_check_error4(n, c, fd);
	if (n)
		ft_putstr_fd("\n", fd);
	exit(0);
}
