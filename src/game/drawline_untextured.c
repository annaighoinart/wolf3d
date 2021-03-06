/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_untextured.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:13:29 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 14:50:33 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	floordraw(int i, int x, t_pr *w)
{
	while (i != 0 && i != WH)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = 5719381;
		i++;
	}
}

static void	ceilingdraw(int i, int x, t_pr *w)
{
	while (i != 0 && i != WH)
	{
		i--;
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = 6165077;
	}
}

void		drawline_untextured(int x, t_pr *w)
{
	int i;
	int k;

	k = 0;
	i = w->drawstart;
	while (i != w->drawend)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = w->color;
		if (w->drawend > WH && i == WH)
			break ;
		else if (w->drawend < 0 && i == 0)
			break ;
		if (i < w->drawend)
			i++;
		else
			i--;
		k++;
	}
	floordraw(i, x, w);
	i = w->drawstart;
	ceilingdraw(i, x, w);
}
