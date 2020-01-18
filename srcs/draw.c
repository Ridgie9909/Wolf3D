/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:16:39 by rdube             #+#    #+#             */
/*   Updated: 2019/10/22 16:59:34 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pxl_to_img(t_wolf *t, int x, int y, int color)
{
	if (t->texture == 1 && x < 1024 && y < 768)
	{
		t->textY = abs((((y * 256 - 768 * 128 + t->lineheight * 128) * 64)
					/ t->lineheight) / 256);
		ft_memcpy(t->image_pointer + 4 * 1024 * y + x * 4,
				&t->tex[t->id].data[t->textY % 64 * t->tex[t->id].sizeline +
				t->textX % 64 * t->tex[t->id].bpp / 8], sizeof(int));
	}
	else if (x < 1024 && y < 768)
		ft_memcpy(t->image_pointer + 4 * 1024 * y + x * 4,
				&color, sizeof(int));
}

void	draw_wall(int x, int start, int end, t_wolf *t)
{
	if (t->texture == 1)
	{
		t->id = t->plane[t->mapX][t->mapY];
		if (t->side == 0)
			t->wallX = t->rayposY + t->walldist * t->raydirY;
		else
			t->wallX = t->rayposX + t->walldist * t->raydirX;
		t->textX = (int)(t->wallX * (double)(64));
		if (t->side == 0 && t->raydirX > 0)
			t->textX = 64 - t->textX - 1;
		if (t->side == 1 && t->raydirY < 0)
			t->textX = 64 - t->textX - 1;
		t->textX = abs(t->textX);
	}
	while (++start <= end)
		put_pxl_to_img(t, x, start, t->color);
}

void	draw_sky(t_wolf *t)
{
	t->textX = 0;
	while (t->textX < 1024)
	{
		t->textY = 0;
		while (t->textY < 768 / 2)
		{
			ft_memcpy(t->image_pointer + 4 * 1024 * t->textY + t->textX * 4,
					&t->tex[6].data[t->textY % 512 * t->tex[6].sizeline +
					t->textX % 512 * t->tex[6].bpp / 8], sizeof(int));
			t->textY++;
		}
		t->textX++;
	}
}

void	draw_floor(t_wolf *t)
{
	t->textX = 0;
	while (t->textX < 1024)
	{
		t->textY = 768 / 2;
		while (t->textY < 768)
		{
			ft_memcpy(t->image_pointer + 4 * 1024 * t->textY + t->textX * 4,
					&t->tex[5].data[t->textY % 64 * t->tex[5].sizeline +
					t->textX % 64 * t->tex[5].bpp / 8], sizeof(int));
			t->textY++;
		}
		t->textX++;
	}
}
