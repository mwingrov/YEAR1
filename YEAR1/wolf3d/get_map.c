/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:15:29 by mwingrov          #+#    #+#             */
/*   Updated: 2017/07/22 17:47:38 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "wolf3d.h"

void	get_map(char **line)
{
	int		fd;
	int		ret;

	fd = open("map.txt", RDWR);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, line);
	if (close(fd) == -1)
	{
		ft_putstr("Error");
		return (1);
	}
}
