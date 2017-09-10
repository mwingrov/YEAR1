/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:14:06 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/10 20:59:50 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*psycho;
	size_t	x;

	x = -1;
	psycho = dest;
	while (++x < n)
	{
		*(psycho + x) = *((unsigned char *)src + x);
		if (*((unsigned char *)src + x) == (unsigned char)c)
			return (dest + x + 1);
	}
	return (NULL);
}
