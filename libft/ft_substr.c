/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:44:27 by fhyman            #+#    #+#             */
/*   Updated: 2021/03/04 21:28:40 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*new;

	i = 0;
	k = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && k < len)
		{
			*(new + k) = *(s + i);
			k++;
		}
		i++;
	}
	*(new + k) = '\0';
	return (new);
}
