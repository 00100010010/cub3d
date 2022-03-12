/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:47:42 by jim               #+#    #+#             */
/*   Updated: 2020/11/07 13:53:23 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			free_txtr(t_tex *tx, void *mlx_ptr)
{
	if (tx->addr)
		mlx_destroy_image(mlx_ptr, tx->ptr);
	if (tx->leak)
		free(tx->name);
}

void			free_all_txtrs(t_c *c)
{
	int		i;

	i = -1;
	while (++i <= 9)
		free_txtr(c->txtrs_list[i], c->mlx_ptr);
}

void			free_mlx(t_c *c)
{
	if (c->check.mlx_img)
		mlx_destroy_image(c->mlx_ptr, c->img.ptr);
	if (c->check.mlx_win)
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
	if (c->check.mlx_init)
		free(c->mlx_ptr);
}

void			free_maps(t_c *c)
{
	int		i;

	i = 0;
	while (c->check.map && i <= c->map.y_cpy)
		free(c->map.map[i++]);
	if (c->check.map)
		free(c->map.map);
	i = 0;
	while (c->check.maper && i <= c->maper.y_max)
		free(c->maper.memory[i++]);
	if (c->check.maper && i)
		free(c->maper.memory);
	while (c->check.mlx_init && c->cubfile_y >= 0)
		free(c->cubfile[c->cubfile_y--]);
	if (c->check.cubfile)
		free(c->cubfile);
	if (c->check.sprts)
		free(c->sprt.sprts);
	if (c->check.zbuffer)
		free(c->sprt.zbuffer);
	if (c->check.tracks)
		free(c->maper.tracks);
}

void			emergency_exit_txtrs_and_id(t_c *c, char *str1,
														char *str2, int code)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	ft_check_error(code, c);
}
