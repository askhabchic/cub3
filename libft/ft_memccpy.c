/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:58:31 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 13:11:12 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*chdst;
	unsigned char	*chsrc;
	size_t			i;

	i = 0;
	chdst = (unsigned char *)dst;
	chsrc = (unsigned char *)src;
	while (i < n)
	{
		chdst[i] = chsrc[i];
		if (chsrc[i] == (unsigned char)c)
			return ((void *)&dst[i + 1]);
		i++;
	}
	return (NULL);
}
