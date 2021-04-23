/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:25:32 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 12:18:32 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1) != 0)
		s1++;
	i = ft_strlen(s1);
	while (i != 0 && ft_strchr(set, s1[i]) != 0)
		i--;
	s2 = ft_substr((char *)s1, 0, i + 1);
	return (s2);
}
