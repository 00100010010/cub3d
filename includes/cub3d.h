/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:32:54 by jim               #+#    #+#             */
/*   Updated: 2020/11/08 11:42:14 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_TITLE "CUB3D"
# define SPEED_MOVE 1.5
# define SPEED_ROTATION 0.09
# define SPEED_WALK 0.15
# define GUN_NAME "textures/sword_5.xpm"
# define FULL_SKY "textures/full_sky_2.xpm"
# define SPRT2_NAME "textures/card2.xpm"
# define VMOVE 0.
# define UDIV 3
# define VDIV 2

# include "keyboard_cub3d.h"
# include "structures_cub3d.h"
# include <stdlib.h>
# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "../minilibx_macos/mlx_png.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

void	read_tex(char *line, t_c *c, int i);
void	read_tex_id(t_c *c, char *line, char *id, int k);
void	read_cub_file_color(char *id, char *line, t_c *c, int k);
char	*mark_endline(char *line, int k, t_c *c, char *id);
void	read_tex_name(char *line, t_tex *tx, int k);
int		put_rgb(t_c *c, t_tex *tex, char *line);
int		pick_line_color(t_tex *tex, char *line, int k);
void	check_txtrs(t_c *c);
void	emergency_exit_txtrs(t_c *c, char *str1, int code);
void	read_file(t_c *c);
void	check_argv(t_c *c, int ac, char **av);
int		init_cub_file(t_c *c, int ac, char **av);
char	**tab_transfer(char **tab, char *str, int vlen, t_c *c);
void	emergency_free_res(int i, char **str1, char *str2);
char	**make_tab_from_file(int fd, t_c *c);
void	init_tx_tab(t_c *c);
void	init_txtrs(t_c *c);
int		init_cub_file(t_c *c, int ac, char **av);
int		read_res(char *line, t_c *c, int i);
int		map_strlen(const char *str, t_c *c);
char	*ft_map_checker(const char *s1, t_c *c);
void	read_map(char **map_file, t_c *c, int k);
char	*next_word(char *line);
int		len_before_space(char *line);
int		count_next_spaces(const char *str);
char	mark_target(t_c *c, int y, char x);
void	adjust_middle_spaces(t_c *c);
int		len_before_endline(char *line);
int		make_screenshot(t_c *c);
void	check_depth_search(t_c *c);
void	maper_back_track(t_c *c);
void	maper_mv(t_c *c);
void	maper_mv_2(t_c *c);
void	init_maper(t_c *c);
int		maper_count_ways(t_c *c);
int		maper_count_ways2(t_c *c);
void	put_map_limits(t_c *c);
void	save_checkpoint(t_c *c);
void	emergency_free_maper(t_c *c, int i);
int		rgb(int r, int g, int b);
void	moving_engine(t_c *c);
void	mv_right_left(t_cam *cam, t_mv *mv);
void	mv_lat_left(t_cam *cam, t_mv *mv, t_map *map);
void	mv_lat_right(t_cam *cam, t_mv *mv, t_map *map);
void	mv_up(t_cam *cam, t_mv *mv, t_map *map);
void	mv_down(t_cam *cam, t_mv *mv, t_map *map);
int		keyboard_input(int key, t_c *c);
int		keyboard_release(int key, t_c *c);
void	keylock_settings(t_c *c);
void	ft_check_error(int n, t_c *c);
void	ft_check_error2(int n, t_c *c, int fd);
void	ft_check_error3(int n, t_c *c, int fd);
void	ft_check_error4(int n, t_c *c, int fd);
void	free_txtr(t_tex *tx, void *mlx_ptr);
void	free_all_txtrs(t_c *c);
void	free_mlx(t_c *c);
void	free_maps(t_c *c);
void	emergency_exit_txtrs_and_id(t_c *c, char *str1, char *str2, int code);
void	key1(t_c *c);
void	key2(t_c *c);
void	key3(t_c *c);
int		ft_close(t_c *c);
void	init_image(t_c *c);
void	init_window(t_c *c);
void	init_mlx(t_c *c);
void	calculate_hit(t_c *c);
void	init_cam_axe(t_c *c);
void	casting_engine(t_c *c);
void	pose_base(t_ray *ray, int res_x, t_cam *cam, int x);
void	vecteur_dir_longueur_seg(t_ray *ray);
void	wall_hit(t_ray *ray, char **map);
void	prepa_casting(t_ray *ray, t_map *map);
void	sprt_casting(t_c *c);
void	sprt2(t_sprt *sprt, t_cam *cam, int i);
void	sprt3(t_sprt *sprt);
void	sprt4(t_sprt *sprt, t_txtrs *txtrs, int i, t_c *c);
void	sprt5(t_sprt *sprt, t_txtrs *txtrs, int stripe, t_c *c);
void	sprt5_b(t_sprt *sprt, t_txtrs *txtrs, int stripe, t_c *c);
void	sort_sprts(t_cam *cam, t_sprt *sprt);
int		change_order_sprts(t_sprt *sprt, int i);
void	set_reflect(t_c *c, int stripe, int color);
void	set_reflect_2(t_c *c, int stripe, int color);
void	sprt_casting(t_c *c);
void	wall_casting(t_c *c, int x);
void	floor_casting(t_c *c, int x);
void	ft_atoi_res(const char *str, t_c *c);
void	weapon_casting(t_c *c, t_tex *tex);
void	fullsky_casting(t_c *c, t_tex *tex);
void	add_sprt_data(t_c *c, int y, int x, int type);
void	init_sprts(t_c *c);
char	**reverse_map(t_c *c, int i, int y, char **map_file);

#endif
