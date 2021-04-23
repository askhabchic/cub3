/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:19:41 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 13:09:35 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*cstr;
	size_t			i;

	cdst = (unsigned char *)dst;
	cstr = (unsigned char *)src;
	i = len;
	if (cdst > cstr)
	{
		while (i--)
			cdst[i] = cstr[i];
	}
	else if (cstr > cdst)
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = cstr[i];
			i++;
		}
	}
	return (dst);
}
