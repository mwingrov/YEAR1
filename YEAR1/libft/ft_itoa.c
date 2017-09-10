/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 00:23:20 by mwingrov          #+#    #+#             */
/*   Updated: 2017/08/07 11:51:56 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(int n)
{
	int	ps;

	ps = 1;
	while (n /= 10)
		ps++;
	return (ps);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	cpy;

	len = ft_strlen(n);
	cpy = n;
	if (n < 0)
	{
		cpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = cpy % 10 + '0';
	while (cpy /= 10)
		str[--len] = cpy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
