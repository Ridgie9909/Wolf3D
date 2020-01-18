/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:18:17 by rdube             #+#    #+#             */
/*   Updated: 2018/06/08 12:40:36 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_and_words(char const *a, char b)
{
	size_t	number_and_words;
	size_t	i;

	i = 0;
	number_and_words = 0;
	if (a[i] && (a[i] != b) && (a[i + 1] != b) && (a[i + 1] != 0))
		number_and_words++;
	while (a[i])
	{
		if ((a[i] == b) && (a[i + 1] != b) && (a[i + 1] != 0))
			number_and_words++;
		i++;
	}
	return (number_and_words);
}

static int	ft_splitstr(char **variables, const char *a, char b, size_t length)
{
	size_t	word_count;
	size_t	word_length;
	size_t	i;

	word_count = 0;
	i = 0;
	while (word_count < length)
	{
		word_length = 0;
		while (a[i] == b && a[i])
			i++;
		while (a[i] != b && a[i])
		{
			word_length++;
			i++;
		}
		if ((variables[word_count] = ft_strsub(&a[i -
						word_length], 0, word_length)) == NULL)
			return (0);
		word_count++;
	}
	variables[word_count] = 0;
	return (1);
}

char		**ft_strsplit(char const *a, char c)
{
	char	**variables;
	int		length;

	if (!a)
		return (NULL);
	length = ft_number_and_words(a, c);
	if ((variables = ((char **)
					ft_memalloc(sizeof(char *) * length + 1))) == NULL)
		return (NULL);
	if (ft_splitstr(variables, a, c, length))
		return (variables);
	else
		ft_memdel((void **)variables);
	return (variables);
}
