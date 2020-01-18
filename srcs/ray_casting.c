/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:30:00 by rdube             #+#    #+#             */
/*   Updated: 2019/10/22 16:49:48 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dda_init(t_wolf *t)
{
	t->deltadistX = sqrt(1 + (t->raydirY * t->raydirY)
			/ (t->raydirX* t->raydirX));
	t->deltadistY = sqrt(1 + (t->raydirX * t->raydirX)
			/ (t->raydirY * t->raydirY));
	if (t->raydirX < 0)
	{
		t->stepX = -1;
		t->sidedistX = (t->rayposX - t->mapX) * t->deltadistX;
	}
	else
	{
		t->stepX = 1;
		t->sidedistX = (t->mapX + 1.0 - t->rayposX) * t->deltadistX;
	}
	if (t->raydirY < 0)
	{
		t->stepY = -1;
		t->sidedistY = (t->rayposY - t->mapY) * t->deltadistY;
	}
	else
	{
		t->stepY = 1;
		t->sidedistY = (t->mapY + 1.0 - t->rayposY) * t->deltadistY;
	}
}

void	dda(t_wolf *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->sidedistX < t->sidedistY)
		{
			t->sidedistX += t->deltadistX;
			t->mapX += t->stepX;
			t->side = 0;
		}
		else
		{
			t->sidedistY += t->deltadistY;
			t->mapY += t->stepY;
			t->side = 1;
		}
		if (t->plane[t->mapX][t->mapY] > 0)
			t->hit = 1;
	}
}

void	ray_casting_init(t_wolf *t, int x)
{
	t->camX = 2 * x / (double)(1024) - 1;
	t->rayposX = t->posX;
	t->rayposY = t->posY;
	t->raydirX = t->dirX + t->planeX * t->camX;
	t->raydirY = t->dirY + t->planeY * t->camX;
	t->mapX = (int)t->rayposX;
	t->mapY = (int)t->rayposY;
	dda_init(t);
	dda(t);
	if (t->side == 0)
		t->walldist = (t->mapX - t->rayposX +
				(1 - t->stepX) / 2) / t->raydirX;
	else
		t->walldist = (t->mapY - t->rayposY +
				(1 - t->stepY) / 2) / t->raydirY;
}

void	floor_and_ceiling(t_wolf *t, int x)
{
	if (t->texture == 0){

		if (t->start > 0)
		{
			t->color = 0x000000;//Sky
			t->y = -1;
			if (x < 1024 && t->y < 768)
				while (++t->y < t->start)
				{
					ft_memcpy(t->image_pointer + 4 * 1024 * t->y + x * 4,
							&t->color, sizeof(int));
				}
		}
	}
	if (t->end > 0)
	{
		t->color = 0xee7600;//Floor
		t->y = t->end - 1;
		if (x < 1024 && t->y < 768)
			while (++t->y < 768)
				ft_memcpy(t->image_pointer + 4 * 1024 * t->y + x * 4,
						&t->color, sizeof(int));
	}
}

void	ray_casting(t_wolf *t)
{
	t->x = -1;//start point for screen
	t->image = mlx_new_image(t->mlx, 1024, 768);
	t->image_pointer = mlx_get_data_addr(t->image, &t->bpp, &t->sl, &t->endian);
	while (++t->x < 1024)
	{
		ray_casting_init(t, t->x);
		t->lineheight = (int)(768 / t->walldist);
		t->start = -t->lineheight / 2 + 768 / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineheight / 2 + 768 / 2;
		if (t->end >= 768)
			t->end = 768 - 1;
		if (t->side == 1)
			t->color = 0x8b0000;// Wall
		else
			t->color = 0x008000;//Wall
		draw_wall(t->x, t->start - 1, t->end, t);
	}
	mlx_put_image_to_window(t->mlx, t->window, t->image, 0, 0);
	mlx_destroy_image(t->mlx, t->image);
}
