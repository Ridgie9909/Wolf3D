/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:14:38 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:35:34 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	else
	{
		while (--n && *s1 && *s2 && ((unsigned char)*s1 == (unsigned char)*s2))
		{
			++s1;
			++s2;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
