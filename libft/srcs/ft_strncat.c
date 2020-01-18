/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:13:32 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:45:57 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *ret;

	ret = dst;
	while (*dst)
	{
		dst++;
	}
	while (n--)
	{
		if (!(*dst++ = *src++))
		{
			return (ret);
		}
		*dst = 0;
	}
	return (ret);
}
