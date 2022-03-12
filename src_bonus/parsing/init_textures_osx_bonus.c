/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_osx_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:21:08 by jim               #+#    #+#             */
/*   Updated: 2020/11/04 18:27:55 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void				init_tx_tab(t_c *c)
{
	c->txtrs.gun.name = GUN_NAME;
	c->txtrs.fullsky.name = FULL_SKY;
	c->txtrs.sprt2.name = SPRT2_NAME;
	c->txtrs_list[0] = &c->txtrs.sky;
	c->txtrs_list[1] = &c->txtrs.floor;
	c->txtrs_list[2] = &c->txtrs.gun;
	c->txtrs_list[3] = &c->txtrs.wall_so;
	c->txtrs_list[4] = &c->txtrs.wall_no;
	c->txtrs_list[5] = &c->txtrs.wall_ea;
	c->txtrs_list[6] = &c->txtrs.wall_we;
	c->txtrs_list[7] = &c->txtrs.sprt;
	c->txtrs_list[8] = &c->txtrs.sprt2;
	c->txtrs_list[9] = &c->txtrs.fullsky;
}

void				set_id(t_tex *tex)
{
	int		i;

	i = 0;
	while (tex->name[i])
		i++;
	tex->id = ft_substr(tex->name, i - 4, 4);
}

int					init_txtrs2(t_tex *tx, void *mlx_ptr)
{
	if (!tx->name)
		return (1);
	if (open(tx->name, O_RDONLY) == -1)
		return (0);
	set_id(tx);
	if (!ft_strncmp(tx->id, ".xpm", 4))
		tx->ptr = mlx_xpm_file_to_image(mlx_ptr, tx->name, &tx->w, &tx->h);
	else if (!ft_strncmp(tx->id, ".png", 4))
		tx->ptr = mlx_png_file_to_image(mlx_ptr, tx->name, &tx->w, &tx->h);
	free(tx->id);
	tx->addr = (unsigned int*)mlx_get_data_addr(tx->ptr, &tx->bpp, &tx->size_l,
																&tx->endian);
	return (1);
}

void				init_txtrs(t_c *c)
{
	int		i;

	i = 0;
	while (i <= 9)
	{
		if (!init_txtrs2(c->txtrs_list[i], c->mlx_ptr))
			ft_check_error(21, c);
		i++;
	}
}
