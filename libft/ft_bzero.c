/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:39:12 by fhyman            #+#    #+#             */
/*   Updated: 2020/11/23 21:05:26 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = s;
	while (i < len)
	{
		arr[i] = '\0';
		i++;
	}
}
