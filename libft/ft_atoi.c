/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:35:32 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/22 19:46:55 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str == NULL || (ft_isdigit(str[i]) != 1 && str[i] != ' '))
	{
		printf("Error: invalid color is given");
		exit (1);
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		str++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		str++;
	}
	return (res);
}
