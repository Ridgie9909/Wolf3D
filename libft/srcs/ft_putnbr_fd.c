/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:06:40 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:21:20 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	while (nbr / 10 > 0)
	{
		ft_putnbr_fd(nbr / 10, fd);
		nbr %= 10;
	}
	ft_putchar_fd(nbr + 48, fd);
}
