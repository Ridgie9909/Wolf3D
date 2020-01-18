/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:56:22 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:10:49 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		verif_char(char *str, char c, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (i);
}

void			ft_inter(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		if (verif_char(s1, s1[i], 1) == 1)
		{
			j = 0;
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					write(1, &s1[i], 1);
					break ;
				}
				j++;
			}
		}
		i++;
	}
	write(1, "\n", 1);
}
