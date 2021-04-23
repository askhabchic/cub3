/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyman <fhyman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:52:40 by fhyman            #+#    #+#             */
/*   Updated: 2021/04/18 13:09:08 by fhyman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_putnbr(int n, int fd)
{
	char		c;

	if (n == 0)
		return ;
	ft_rec_putnbr(n / 10, fd);
	c = n % 10;
	if (c < 0)
		c = -1 * c;
	c += 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	ft_rec_putnbr(n, fd);
}
