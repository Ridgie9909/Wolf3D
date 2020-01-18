/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:03:59 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:15:17 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char *s2;

	if (str1 == str2 || n == 0)
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
