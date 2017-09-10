/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:51:32 by mwingrov          #+#    #+#             */
/*   Updated: 2017/07/23 10:48:32 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_rotate(int keycode, double tmp_dir, double tmp_plane, t_env *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 0)
	{
		mlx->player.xdrc = mlx->player.xdrc * cos(mlx->player.rtspeed)
			- mlx->player.ydrc * sin(mlx->player.rtspeed);
		mlx->player.ydrc = tmp_dir * sin(mlx->player.rtspeed)
			+ mlx->player.ydrc * cos(mlx->player.rtspeed);
		mlx->cam.xplane = mlx->cam.xplane * cos(mlx->player.rtspeed)
			- mlx->cam.yplane * sin(mlx->player.rtspeed);
		mlx->cam.yplane = tmp_plane * sin(mlx->player.rtspeed)
			+ mlx->cam.yplane * cos(mlx->player.rtspeed);
	}
	if (keycode == 124 || keycode == 2)
	{
		mlx->player.xdrc = mlx->player.xdrc * cos(-mlx->player.rtspeed)
			- mlx->player.ydrc * sin(-mlx->player.rtspeed);
		mlx->player.ydrc = tmp_dir * sin(-mlx->player.rtspeed)
			+ mlx->player.ydrc * cos(-mlx->player.rtspeed);
		mlx->cam.xplane = mlx->cam.xplane * cos(-mlx->player.rtspeed)
			- mlx->cam.yplane * sin(-mlx->player.rtspeed);
		mlx->cam.yplane = tmp_plane * sin(-mlx->player.rtspeed)
			+ mlx->cam.yplane * cos(-mlx->player.rtspeed);
	}
	return (0);
}

static int	ft_sprint(int keycode, t_env *mlx)
{
	if (keycode == 257)
	{
		if (mlx->player.sprint == 0)
		{
			mlx->player.mvspd = 0.2;
		}
		else
		{
			mlx->player.mvspd = 0.2;
		}
	}
	ft_draw(mlx);
	return (0);
}

static int	ft_keyy(int keycode, t_env *mlx)
{
	if (keycode == 125 || keycode == 1)
	{
		if (mlx->map[(int)(mlx->player.xposi - mlx->
					player.xdrc * mlx->player.mvspd)]
				[(int)(mlx->player.yposi)] != '1')
			mlx->player.xposi -= mlx->player.xdrc * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xposi)]
				[(int)(mlx->player.yposi - mlx->
					player.ydrc * mlx->player.mvspd)] != '1')
			mlx->player.yposi -= mlx->player.ydrc * mlx->player.mvspd;
		if (keycode == 78 || keycode == 27)
			mlx->dh = (mlx->dh < 120) ? mlx->dh + 0.5 : mlx->dh;
		if (keycode == 69 || keycode == 24)
		{
			mlx->dh = (mlx->dh > 0.5) ? mlx->dh - 0.5 : mlx->dh;
			ft_rotate(keycode, mlx->player.xdrc, mlx->cam.xplane, mlx);
			ft_sprint(keycode, mlx);
		}
	}
	return (0);
}

int			key_press(int keycode, t_env *mlx)
{
	if (keycode == 126 || keycode == 13)
	{
		if (mlx->map[(int)(mlx->player.xposi +
					mlx->player.ydrc * mlx->player.mvspd)]
				[(int)(mlx->player.yposi)] != '1')
			mlx->player.xposi += mlx->player.xdrc * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xposi)][(int)(mlx->player.yposi
					+ mlx->player.ydrc * mlx->player.mvspd)] != '1')
			mlx->player.yposi += mlx->player.ydrc * mlx->player.mvspd;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (mlx->map[(int)(mlx->player.xposi - mlx->
					player.xdrc * mlx->player.mvspd)]
				[(int)(mlx->player.yposi)] != '1')
			mlx->player.xposi -= mlx->player.xdrc * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xposi)][(int)(mlx->player.yposi
					- mlx->player.ydrc * mlx->player.mvspd)] != '1')
			mlx->player.yposi -= mlx->player.ydrc * mlx->player.mvspd;
	}
	ft_rotate(keycode, mlx->player.xdrc, mlx->cam.xplane, mlx);
	ft_sprint(keycode, mlx);
	ft_keyy(keycode, mlx);
	return (0);
}
