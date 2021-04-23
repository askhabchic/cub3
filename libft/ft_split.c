/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:07:03 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 13:08:28 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_word_free(char **arr, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*fill_word(char *s, char c)
{
	size_t			i;
	char			*array;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	array[i] = '\0';
	while (i--)
		array[i] = s[i];
	return (array);
}

static char	**content(char **arr, char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		arr[count] = fill_word(s, c);
		if (!arr[count])
			return (ft_word_free(arr, count));
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	arr[count] = NULL;
	return (arr);
}

static unsigned int	words_count(char *s, char c)
{
	unsigned int	aword;
	unsigned int	words;

	aword = 0;
	words = 0;
	while (*s)
	{
		if (*s == c && aword)
		{
			words++;
			aword = 0;
		}
		else if (*s != c)
			aword = 1;
		s++;
	}
	if (aword)
		words++;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	unsigned char	num;
	char			**arr;

	if (s == NULL)
		return (NULL);
	num = words_count((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (num + 1));
	if (arr == NULL)
		return (NULL);
	if (!(content(arr, (char *)s, c)))
		return (NULL);
	return (arr);
}
