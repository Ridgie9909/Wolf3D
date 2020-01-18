/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:16:09 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:40:10 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		len;

	len = ft_strlen((char *)src);
	while (0 != len && src[len] != (char)c)
		len--;
	if (src[len] == (char)c)
		return ((char *)&src[len]);
	return (NULL);
}
