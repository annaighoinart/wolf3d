/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:47:21 by atabala           #+#    #+#             */
/*   Updated: 2019/06/03 15:52:20 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/wolf3d.h"

void	validation(int argc, char **argv, t_pr *w)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./wolf3d map_name\n");
		exit (0);
	}
}