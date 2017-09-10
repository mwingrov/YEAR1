/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 12:00:09 by mwingrov          #+#    #+#             */
/*   Updated: 2017/07/22 16:39:42 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct		s_type
{
	double			x;
	double			y;
}					t_type;

typedef struct		s_map
{
	int				x;
	int				y;
}					t_map;

typedef struct		s_move
{
	int		up;
	int		down;
	int		left;
	int		right;
}					t_move;

typedef struct		s_ray
{
	t_type		pos;
	t_type		dir;
	t_type		plane;
	t_type		sidedist;
	t_type		disd;
	t_map		posmap;
	int			lheight;
	int			ystart;
	int			yend;
}					t_ray;

typedef struct	s_player
{
	t_type		pos;
	t_type		dir;
	t_map		step;
	t_move		move;
	double		rspeed;
	double		mspeed;
	double		hcamera;
	int			hit;
	int			wallside;
	int			sprint;
}				t_player;

typedef struct	s_rmap
{
	int		**map;
	int		display;
	int		sizex;
	int		sizey;
}				t_rmap;

typedef struct	s_img
{
	void	*img;
	char	*d;
	int		bp;
	int		s;
	int		e;
}				t_img;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_player	player;
	t_rmap		map;
	t_ray		r;
	int			drawStart;
	int			drawEnd;
	double		time;
	double		oldtime;
	long int	frametime;
}				t_env;

static int	ft_rotate(int keycode, double tmp_dir, double tmp_plane, t_mlx *mlx);
static int	ft_sprint(int keycode, t_mlx *mlx);
static int	ft_keyy(int keycode, t_mlx *mlx);
int			key_press(int keycode, t_mlx *mlx);

#endif
