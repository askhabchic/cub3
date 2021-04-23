/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:28:53 by fhyman            #+#    #+#             */
/*   Updated: 2020/11/21 16:43:41 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*arr;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	arr = malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	*(arr + i) = '\0';
	while (i--)
		arr[i] = f(i, s[i]);
	return (arr);
}
