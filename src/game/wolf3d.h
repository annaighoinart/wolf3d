/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:59:30 by atabala           #+#    #+#             */
/*   Updated: 2019/06/13 14:58:06 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../../minilibx_macos/mlx.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WW w->win_width
# define WH w->win_height
# define INIT int wid;int hei;wid=64;hei=64

typedef struct		s_pr
{
	int				fd;
	int				**map;
	char			**parsemap;

	int				maplen;
	int				found_coord;

	void			*mlx_ptr;
	void			*win_ptr;

	int				win_width;
	int				win_height;

	void			*win_minimap;

	void			*img_ptr;
	int				*imgdata;

	void			*img_t1;
	int				*img_t1_d;

	void			*img_t4;
	int				*img_t4_d;

	void			*img_t3;
	int				*img_t3_d;

	void			*img_t2;
	int				*img_t2_d;

	void			*img_t1_1;
	int				*img_t1_1_d;

	void			*img_t4_1;
	int				*img_t4_1_d;

	void			*img_t3_1;
	int				*img_t3_1_d;

	void			*img_t2_1;
	int				*img_t2_1_d;

	int				t_wh;

	void			*img_awp;
	int				*img_awp_d;
	int				awp_w;
	int				awp_h;

	void			*img_sky;
	int				*img_sky_d;
	int				sky_w;
	int				sky_h;

	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;

	double			camerax;
	double			raydirx;
	double			raydiry;

	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;

	double			olddirx;
	double			oldplanex;

	double			movespeed;
	double			rotspeed;

	int				hit;
	int				side;

	int				lineheight;
	int				drawstart;
	int				drawend;

	int				mapwidth;
	int				mapheight;

	int				prevxmouse;

	char			*argv;
	int				color;
	int				*texture;

	int				prevp;
	int				x_text;

	int				texi;
	int				texd;

	int				textured;
}					t_pr;

void				readmap(t_pr *w);
int					mouse_move(int x, int y, t_pr *w);
void				count(t_pr *w);
void				img(t_pr *w);

void				settextures(t_pr *w);
void				set_textures(int x, t_pr *w);
void				set_color(int x, t_pr *w);
void				draw(t_pr *w);
void				drawline_textured(int *texture, int x, t_pr *w);
void				drawline_untextured(int x, t_pr *w);
void				textured(t_pr *w);
void				indentation(char *argv, t_pr *w);
void				move(int i, t_pr *w);
void				validation(int argc, char **argv, t_pr *w);
void				controlsmenu(t_pr *w);

#endif
