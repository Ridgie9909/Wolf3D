/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:08:36 by rdube             #+#    #+#             */
/*   Updated: 2019/10/22 16:42:13 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	mlx_win_init(t_wolf *t)
{
	t->mlx = mlx_init();
	t->window = mlx_new_window(t->mlx, 1024, 768, "Wolf3D");
}

void	wolf3d_init(t_wolf *t)
{
	t->posX = 3;
	t->posY = 3;
	t->dirX = -1;
	t->dirY = 0;
	t->planeX = 0;
	t->planeY = 0.66;
	t->ms = 0.05;
	t->rs = 0.1;
	t->moveUp = 0;
	t->moveDown = 0;
	t->moveLeft = 0;
	t->moveRight = 0;
	t->textX = 0;
	t->textY = 0;
}

int		main(int argc, char **argv)
{
	t_wolf *t;

	if (argc != 2)
	{
		ft_putstr("Please run the Executable with atleast some type of data\n");
		return (0);
	}
	if (!(t = (t_wolf *)malloc(sizeof(t_wolf))))
		return (0);
	if (!(analyser(t, argv)))
		return (0);
	mlx_win_init(t);
	mlx_hook(t->window, 17, 0, ft_close, t);
	mlx_hook(t->window, 2, (1 << 0), key_press, t);
	mlx_hook(t->window, 3, (1 << 1), key_release, t);
	wolf3d_init(t);
	ray_casting(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
