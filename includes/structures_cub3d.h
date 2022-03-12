/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_cub3d.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:32:54 by jim               #+#    #+#             */
/*   Updated: 2020/11/07 15:25:13 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_CUB3D_H
# define STRUCTURES_CUB3D_H

typedef struct			s_cam
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camerax;
	char		axe;

}						t_cam;

typedef	struct			s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			deltadistx;
	double			deltadisty;
	double			side_dist_x;
	double			side_dist_y;
	double			side;
	double			prpwalldist;
	double			step_x;
	double			step_y;
	double			map_x;
	double			map_y;
	double			h_line;
	double			wall_x;
	int				draw_start;
	int				draw_end;
	int				sprt;
}						t_ray;

typedef struct			s_mv
{
	int				mv;
	double			rt;
	double			speed_walk;
}						t_mv;

typedef struct			s_tracks
{
	int				x;
	int				y;
}						t_tracks;

typedef struct			s_maper
{
	t_tracks		*tracks;
	int				last_track;
	int				tokens;
	char			**memory;
	unsigned int	x;
	unsigned int	y;
	unsigned int	y_max;
}						t_maper;

typedef	struct			s_key
{
	int			up;
	int			down;
	int			lat_left;
	int			lat_right;
	int			right;
	int			left;
	int			space;
	int			total;
}						t_key;

typedef	struct			s_keylock
{
	int			up_down;
	int			lat;
	int			rt;
}						t_keylock;

typedef struct			s_img
{
	void			*ptr;
	unsigned int	*addr;
	int				size_l;
	int				bpp;
	int				endian;
}						t_img;

typedef struct			s_tex
{
	double			y;
	double			x;
	int				w;
	int				h;
	void			*ptr;
	void			*wall_ptr;
	int				bpp;
	int				size_l;
	int				endian;
	unsigned int	*addr;
	unsigned int	*wall_addr;
	char			*name;
	char			*id;
	int				rgb[3];
	int				rgb_flag;
	char			leak;
	char			full_option;
}						t_tex;

typedef struct			s_sprts
{
	double			dist;
	double			x;
	double			y;
	int				type;
}						t_sprts;

typedef struct			s_sprt
{
	double		*zbuffer;
	t_sprts		*sprts;
	int			amount;
	double		res_h;
	double		res_w;
	double		x;
	double		y;
	double		r_y;
	double		r_z;
	double		iv_dt;
	double		trsnfrm_y;
	double		trsnfrm_x;
	int			scrnx;
	int			vmovscrn;
	int			h;
	int			w;
	int			start_x;
	int			start_y;
	int			drawend_x;
	int			drawend_y;
	char		type;
}						t_sprt;

typedef struct			s_map
{
	char	**map;
	long	res_x;
	long	res_y;
	int		first_spaces;
	int		middle_spaces;
	int		infos_count;
	int		len_secu;
	int		y_cpy;
	int		fd;
}						t_map;

typedef struct			s_txtrs
{
	t_tex	wall_no;
	t_tex	wall_so;
	t_tex	wall_we;
	t_tex	wall_ea;
	t_tex	sprt;
	t_tex	sprt2;
	t_tex	floor;
	t_tex	sky;
	t_tex	gun;
	t_tex	fullsky;
}						t_txtrs;

typedef	struct			s_check
{
	int				res;
	int				txtrs;
	int				map;
	int				maper;
	int				cubfile;
	int				mlx_init;
	int				mlx_win;
	int				mlx_img;
	int				sprts;
	int				zbuffer;
	int				tracks;
}						t_check;

typedef struct			s_screen
{
	unsigned int			filesize;
	unsigned short			reserved1;
	unsigned short			reserved2;
	unsigned int			offset;
	unsigned int			headersize;
	unsigned int			image_width;
	unsigned int			image_height;
	unsigned short			plane;
	unsigned short			bpp;
	unsigned int			compression;
	unsigned int			total_size;
	unsigned int			w_res;
	unsigned int			h_res;
	unsigned int			colors;
	unsigned int			prio_colors;
}						t_screen;

typedef struct			s_c
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_img			img;
	t_cam			cam;
	t_ray			ray;
	t_mv			mv;
	t_key			key;
	t_keylock		keylock;
	t_txtrs			txtrs;
	t_sprt			sprt;
	t_maper			maper;
	t_tex			*txtrs_list[10];
	char			*line;
	t_check			check;
	t_screen		screen;
	char			screenshot;
	char			**cubfile;
	int				cubfile_y;
	int				fd;
}						t_c;

#endif
