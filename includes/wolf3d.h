/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:27:50 by rdube             #+#    #+#             */
/*   Updated: 2018/10/14 15:41:43 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;

typedef struct	s_wolf
{
	t_tex		tex[9];
	char		*map_name;
	void		*mlx;
	void		*window;
	void		*image;
	void		*image_pointer;
	int			**plane;
	int			nb_lines;
	int			linelen;
	int			bpp;
	int			endian;
	int			sl;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			moveUp;
	int			moveDown;
	int			moveLeft;
	int			moveRight;
	int			help;
	int			textX;
	int			textY;
	int			id;
	int			texture;
	int			floortextX;
	int			floortextY;
	int			x;
	int			y;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		camX;
	double		rayposX;
	double		rayposY;
	double		raydirX;
	double		raydirY;
	double		sidedistX;
	double		sidedistY;
	double		deltadistX;
	double		deltadistY;
	double		walldist;
	double		olddirX;
	double		oldplaneX;
	double		ms;
	double		rs;
	double		wallX;
	double		floorX;
	double		floorY;
	double		curfloortextX;
	double		curfloortextY;
	double		curdist;
	double		weight;
}				t_wolf;

void			draw_sky(t_wolf *t);
void			draw_floor(t_wolf *t);
void			draw_wall(int x, int start, int end, t_wolf *t);
void			put_pxl_to_img(t_wolf *t, int x, int y, int color);

int				key_press2(int keycode, t_wolf *t);
int				key_press(int keycode, t_wolf *t);
int				key_release(int keycode, t_wolf *t);
void			move_side(t_wolf *t);
int				move(t_wolf *t);

int				ft_close(void);
void			mlx_win_init(t_wolf *t);
void			wolf_init(t_wolf *t);

int				check_plane(char *buff, t_wolf *t);
int				analyser(t_wolf *t, char **av);
int				analyser2(t_wolf *t, char **av);

void			ray_casting(t_wolf *t);
void			ray_casting_init(t_wolf *t, int x);
void			floor_and_ceiling(t_wolf *t, int x);
void			dda(t_wolf *t);
void			dda_init(t_wolf *t);
#endif
