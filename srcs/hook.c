/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:37:12 by rdube             #+#    #+#             */
/*   Updated: 2019/10/22 16:58:39 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, t_wolf *t)
{
	if (keycode == 13 || keycode == 126)
		t->moveUp = 1;
	else if (keycode == 1 || keycode == 125)
		t->moveDown = 1;
	else if (keycode == 2 || keycode == 124)
		t->moveRight = 1;
	else if (keycode == 0 || keycode == 123)
		t->moveLeft = 1;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.1;
	else if (keycode == 53)
		exit(1);
	return (0);
}

int		key_release(int keycode, t_wolf *t)
{
	if (keycode == 13 || keycode == 126)
		t->moveUp = 0;
	else if (keycode == 1 || keycode == 125)
		t->moveDown = 0;
	else if (keycode == 2 || keycode == 124)
		t->moveRight = 0;
	else if (keycode == 0 || keycode == 123)
		t->moveLeft = 0;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.05;
	return (0);
}

void	move_side(t_wolf *t)
{
	if (t->moveRight == 1)
	{
		t->olddirX = t->dirX;
		t->dirX = t->dirX * cos(-t->rs) - t->dirY * sin(-t->rs);
		t->dirY = t->olddirX * sin(-t->rs) + t->dirY * cos(-t->rs);
		t->oldplaneX = t->planeX;
		t->planeX = t->planeX * cos(-t->rs) - t->planeY * sin(-t->rs);
		t->planeY = t->oldplaneX * sin(-t->rs) + t->planeY * cos(-t->rs);
	}
	if (t->moveLeft == 1)
	{
		t->olddirX = t->dirX;
		t->dirX = t->dirX * cos(t->rs) - t->dirY * sin(t->rs);
		t->dirY = t->olddirX * sin(t->rs) + t->dirY * cos(t->rs);
		t->oldplaneX = t->planeX;
		t->planeX = t->planeX * cos(t->rs) - t->planeY * sin(t->rs);
		t->planeY = t->oldplaneX * sin(t->rs) + t->planeY * cos(t->rs);
	}
}

int		move(t_wolf *t)
{
	if (t->moveUp == 1)
	{
		if (t->plane[(int)(t->posX + t->dirX * t->ms)][(int)(t->posY)] == 0)
			t->posX += t->dirX * t->ms;
		if (t->plane[(int)(t->posX)][(int)(t->posY + t->dirY * t->ms)] == 0)
			t->posY += t->dirY * t->ms;
	}
	if (t->moveDown == 1)
	{
		if (t->plane[(int)(t->posX - t->dirX * t->ms)][(int)(t->posY)] == 0)
			t->posX -= t->dirX * t->ms;
		if (t->plane[(int)(t->posX)][(int)(t->posY - t->dirY * t->ms)] == 0)
			t->posY -= t->dirY * t->ms;
	}
	move_side(t);
	ray_casting(t);
	return (0);
}
