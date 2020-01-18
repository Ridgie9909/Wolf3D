/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:29:22 by rdube             #+#    #+#             */
/*   Updated: 2019/10/22 16:56:41 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_plane(char *buff, t_wolf *t)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	t->linelen = ft_linelen(buff);
	t->nb_lines = ft_countlines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != t->linelen)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int		analyser2(t_wolf *t, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (ft_get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(t->plane[i] = (int *)malloc(sizeof(int) * t->linelen)))
			return (0);
		while (++j < t->linelen)
		{
			if (str[k] == ' ')
				k++;
			t->plane[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	return (1);
}

int		side_checker(t_wolf *t)
{
	int		i;

	i = 0;
	while (i < t->linelen)
	{
		if (t->plane[0][i] == 0)
			return (0);
		if (t->plane[t->nb_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < t->nb_lines)
	{
		if (t->plane[i][0] == 0)
			return (0);
		if (t->plane[i][t->linelen - 1] == 0)
			return (0);
		i++;
	}
	if (t->plane[3][3] != 0)
		return (0);
	return (1);
}

int		analyser(t_wolf *t, char **argv)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
	{
		ft_putstr("Please enter a file with map data\n");
		ft_putstr("\n");
		return (0);
	}
	if (!(check_plane(buff, t)))
	{
		ft_putstr("Map Error\n");
		return (0);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			t->linelen--;
		i++;
	}
	ft_strdel(&buff);
	t->map_name = argv[1];
	close(fd);
	if (!(t->plane = (int **)malloc(sizeof(int *) * t->nb_lines))
			|| !(analyser2(t, argv)))
		return (0);
	if (!side_checker(t))
	{
		ft_putstr("Map Error\n");
		return (0);
	}
	return (1);
}

