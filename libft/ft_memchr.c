/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:40:11 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 13:10:25 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*arr;
	unsigned char		a;

	i = 0;
	arr = s;
	a = c;
	while (i < n)
	{
		if (*(arr + i) == a)
			return ((unsigned char *)(arr + i));
		i++;
	}
	return (NULL);
}
