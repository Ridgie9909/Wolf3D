/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:03:37 by rdube             #+#    #+#             */
/*   Updated: 2018/10/14 15:38:34 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*ptr;
	char	c2;
	int		i;

	i = 0;
	c2 = (char)c;
	ptr = (char *)str;
	while (n--)
	{
		if (ptr[i] == c2)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
