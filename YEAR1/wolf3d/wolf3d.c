/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:44:22 by mwingrov          #+#    #+#             */
/*   Updated: 2017/07/22 17:56:23 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft/libft.h"
#include <mlx.h>
//#include "get_next_line"

int	key_event(int keypress, void *param)
{
	if (keypress == 53)
	exit(0);
	return (0);
}

int	main(void)
{
	t_type	x;
	t_type	y;
	t_env	*win;
	t_env	*mix;

	mlx->mlx = mlx_init();
	win->win = mlx_new_window(mlx, 800, 600, "Wold3D Window");
	down.y = 50;
	while (down.y < 150)
	{
		right.x = 50;
		while (right.x < 150)
		{
			mlx_pixel_put(mlx->mlx, win->win, right.x, down.y, 0xFFFF);
			right.x++;
		}
		down.y++;
	}
	mlx_key_hook(win->win, key_event, 0);
	mlx_loop(mlx->mlx);
}
