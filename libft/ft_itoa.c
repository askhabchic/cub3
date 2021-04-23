/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:38:05 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/21 19:55:45 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*arr;
	char	c;

	i = ft_len(n);
	arr = malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	*(arr + i) = '\0';
	if (n < 0)
		*arr = '-';
	if (!n)
		*arr = '0';
	while (n)
	{
		i--;
		c = n % 10;
		if (c < 0)
			c *= -1;
		*(arr + i) = c + 48;
		n /= 10;
	}
	return (arr);
}
