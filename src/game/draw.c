/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:11:02 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 14:46:41 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	findhit(t_pr *w)
{
	while (w->hit == 0)
	{
		if (w->sidedistx < w->sidedisty)
		{
			w->sidedistx += w->deltadistx;
			w->mapx += w->stepx;
			w->side = 0;
		}
		else
		{
			w->sidedisty += w->deltadisty;
			w->mapy += w->stepy;
			w->side = 1;
		}
		if (w->map[w->mapx][w->mapy] > 0)
			w->hit = 1;
	}
	if (w->prevp == w->map[w->mapx][w->mapy] && w->prevp != 0)
		w->x_text++;
	else
		w->x_text = 0;
	if (w->side == 0)
		w->perpwalldist = (w->mapx - w->posx + (1 - w->stepx) / 2) / w->raydirx;
	else
		w->perpwalldist = (w->mapy - w->posy + (1 - w->stepy) / 2) / w->raydiry;
}

static void	findwall(t_pr *w)
{
	if (w->raydirx < 0)
	{
		w->stepx = -1;
		w->sidedistx = (w->posx - w->mapx) * w->deltadistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedistx = (w->mapx + 1.0 - w->posx) * w->deltadistx;
	}
	if (w->raydiry < 0)
	{
		w->stepy = -1;
		w->sidedisty = (w->posy - w->mapy) * w->deltadisty;
	}
	else
	{
		w->stepy = 1;
		w->sidedisty = (w->mapy + 1.0 - w->posy) * w->deltadisty;
	}
}

static void	allmaths(int x, t_pr *w)
{
	w->camerax = 2 * x / (double)WW - 1;
	w->raydirx = w->dirx + w->planex * w->camerax;
	w->raydiry = w->diry + w->planey * w->camerax;
	w->mapx = (int)w->posx;
	w->mapy = (int)w->posy;
	w->deltadistx = fabs(1 / w->raydirx);
	w->deltadisty = fabs(1 / w->raydiry);
	w->hit = 0;
	findwall(w);
	findhit(w);
	w->lineheight = (int)(WH / w->perpwalldist);
	w->drawstart = -w->lineheight / 2 + WH / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = w->lineheight / 2 + WH / 2;
	if (w->drawend >= WH)
		w->drawend = WH - 1;
}

void		draw(t_pr *w)
{
	int x;

	x = 0;
	while (x < WW)
	{
		allmaths(x, w);
		if (w->textured == 1)
			set_textures(x, w);
		else
			set_color(x, w);
		x++;
	}
}
