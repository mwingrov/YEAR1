/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:55:54 by mwingrov          #+#    #+#             */
/*   Updated: 2017/07/22 17:48:33 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "wolf3d.h"


void	raypos()
{
	t_ray		plane;
	t_ray		dir;
	t_player	pos;
	t_ray		sidedist;

	map.mapx = pos.posx;
	map.mapy = pos.posy;
	sidedist.deltaDistX = sqrt(1 + (dir.dirY / dir.dirX));
	sidedist.deltaDistY = sqrt(1 + (dir.dirX / dir.dirY));
}

void	raydir()
{
	t_player	dir;
	t_player	pos;
	t_ray		sidedist;
	t_player	wallside;
	t_player	step;
	t_ray		dir;
	t_player	pos;
	t_env		map;

	if (dir.dirX < 0)
	{
		step.stepX = -1;
		sidedist.DistX = (pos.posx - map.mapX) * wallside.DistX;
	}
	else
	{
		step.stepX = 1;
		sidedist.DistX = (map.mapX + 1.0 - pos.posx) * walldist.DistX;
	}
	if (dir.dirY < 0)
	{
		step.stepY = -1;
		sidedist.DistY = (pos.posy - map.mapY) * walldist.DistY;
	}
	else
	{
		step.stepY = 1;
		sidedist.DistY = (map.mapY + 1.0 - pos.posy) * walldist.DistY;
	}
}

void	dda()
{
	int			hit;
	int			side;
	t_env		map;
	t_player	step;
	t_type		wallside;
	t_ray		sidedist;

	while (hit == 0)
	{
		if (sidedist.DistX < sidedist.DistY)
		{
			sidedist.DistX += walldist.DistX;
			map.mapX += step.stepX;
			side = 0;
		}
		else
		{
			sidedist.DistY += walldist.DistY;
			map.mapY += step.stepY;
			side = 1;
		}
		if (map.Map[map.mapX][map.mapY] > 0) 
			hit = 1;
	}
}

void	walldist_hight()
{
	t_ray		lheight;
	t_player	walldist;
	t_env		drawStart;
	t_env		drawEnd;
	int			h;

	h = 0;
	lheight.lineHeight = (h / walldist.Dist);
	drawStart.Draw = -lheight.Height / 2 + h / 2;
	if(drawStart.Draw < 0)
	{
		drawStart.Draw = 0;
		drawEnd.Draw = lheight.lineHeight / 2 + h / 2;
		if(drawEnd.Draw >= h)
			drawEnd.Draw = h - 1;
	}
}
