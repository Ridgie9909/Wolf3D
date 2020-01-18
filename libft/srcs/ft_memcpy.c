/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:02:35 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:15:55 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char	*c1;
	char	*c2;

	if (n == 0 || str1 == str2)
		return (str1);
	c1 = (char *)str1;
	c2 = (char *)str2;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (str1);
}
