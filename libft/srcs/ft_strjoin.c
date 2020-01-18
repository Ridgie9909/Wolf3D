/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:11:49 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:30:29 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joided;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joided = ft_strnew(len);
	if (joided == NULL)
		return (NULL);
	ft_strcat(joided, s1);
	ft_strcat(joided, s2);
	return (joided);
}
