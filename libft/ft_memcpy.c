/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:01:06 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 13:10:52 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*chdst;
	unsigned char	*chsrc;

	chdst = (unsigned char *)dst;
	chsrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*chdst++ = *chsrc++;
	return (dst);
}
