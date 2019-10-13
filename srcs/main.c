/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:42:10 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/13 18:53:40 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

ft_check_frac(t_env *e, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbroth") == 0)
		e->fract = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		e->fract = 2;
	else if (ft_strcmp(argv[1], "burnship") == 0)
		e->fract = 3;
	else if (ft_strcmp(argv[1], "burnship_mv") == 0)
		e->fract = 4;
	else
	{
		ft_putendl("Choose one of this fractals:\n->mandelbroth\n->julia\n\
burnship\nburnship_mv\n");
		exit(1);
	}
}

void	ft_check(t_env *e, int argc, char **argv)
{
	if (argc == 2)
	{
		e->winx = 1280;
		e->winy = 720;
	}
	else if (argc == 4)
	{
		e->winx = ft_atoi(argv[2]);
		e->winy = ft_atoi(argv[3]);
		if (e->winx < 400 || e->winy < 300 || e->winx > 2560 || e->winy > 1440)
		{
			ft_putendl("usage: ./fractol fractale_name [400 <= weidth_size <= 2560]\
[800 <= long_size <= 1440]");
			exit(1);
		}
	}
	else
	{
		ft_putendl("usage: ./fractol fractale_name [400 <= weidth_size <= 2560]\
[800 <= long_size <= 1440]");
		// ft_putendl("choose one of this fractals:\n->mandelbroth\n->julia");
		exit(1);
	}
	ft_check_frac(e, argv);
}

void mandelbroth(float x, float y, t_env *e)
{
	int k;
	float zi;
	float zn;
	float zi1;
	float zn1;
	float color;
	float sq;

	k = 0;
	zi1 = y;
	zn1 = x;
	color = 255.0f / e->iter;
	while (k < e->iter && ((sq = sqrt(zn1 * zn1 + zi1 *zi1)) <= 2))
	{
		zn = ABS(zn1);
		zi = ABS(zi1);
		zn1 = zn * zn - zi * zi + x;
		zi1 = 2 * zn * zi + y;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	if (sq >= 2)
		ft_fill_pixel_color(e->x, e->y, (float)((float)k) * color, e);
}

int julia(float x, float y, t_env *e)
{
	int k;
	float zi;
	float zn;
	float zi1;
	float zn1;
	float color;
	float sq;

	k = 0;
	color = 255.0f / (e->iter);
	zi1 = y;
	zn1 = x;
	while (k < e->iter && ((sq = sqrt(zn1 * zn1 + zi1 *zi1)) <= 2))
	{
		zn = zn1;
		zi = zi1;
		zn1 = zn * zn - zi * zi + e->cn;
		zi1 = 2 * zn * zi + e->ci;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	// printf("e->iter = %i, k = %i\n", e->iter, k);
	if (sq >= 2)
		ft_fill_pixel_color(e->x, e->y, (float)((float)k ) * color, e);
	return (k);
}

void burning_ship(float x, float y, t_env *e)
{
	int k;
	float zi;
	float zn;
	float zi1;
	float zn1;
	float color;
	float sq;

	k = 0;
	zi1 = y;
	zn1 = x;
	color = 255.0f / e->iter;
	while (k < e->iter && ((sq = sqrt(zn1 * zn1 + zi1 *zi1)) <= 2))
	{
		zn = ABS(zn1);
		zi = ABS(zi1);
		zn1 = zn * zn - zi * zi + x;
		zi1 = 2 * zn * zi + y;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	if (sq >= 2)
		ft_fill_pixel_color(e->x, e->y, (float)((float)k) * color, e);
}

int burning_ship_move(float x, float y, t_env *e)
{
	int k;
	float zi;
	float zn;
	float zi1;
	float zn1;
	float color;
	float sq;

	k = 0;
	color = 255.0f / (e->iter);
	zi1 = y;
	zn1 = x;
	while (k < e->iter && ((sq = sqrt(zn1 * zn1 + zi1 *zi1)) <= 2))
	{
		zn = ABS(zn1);
		zi = ABS(zi1);
		zn1 = zn * zn - zi * zi + e->cn;
		zi1 = 2 * zn * zi + e->ci;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	// printf("e->iter = %i, k = %i\n", e->iter, k);
	if (sq >= 2)
		ft_fill_pixel_color(e->x, e->y, (float)((float)k ) * color, e);
	return (k);
}

void cross_string(t_env *e)
{
	float x0;
	float y0;
	int maxk;
	int cmp;

	e->y = 0;
	while (e->y < e->winy)
	{
		e->x = 0;
		while (e->x < e->winx)
		{
			// if (e->y < 50)
			// 	dprintf(fd, "x0 = %f, y0 = %f\n", x0, y0);
			x0 = (float)(e->x - (e->repx) + e->depx) / (float)e->convx;
			y0 = (float)(e->y - (e->repy) + e->depy) / (float)e->convy;
			if (e->fract == 1)
				mandelbroth(x0, y0, e);
			else if (e->fract == 2)
				cmp = julia(x0, y0, e);
			else if (e->fract == 3)
				burning_ship(x0, y0, e);
			else if (e->fract == 4)
				burning_ship_move(x0, y0, e);
			if (maxk < cmp)
				maxk = cmp;
			e->x++;
		}
		e->y++;
	}
	// printf("maxk = %i\n", maxk);
}

void move(int keycode, t_env *e)
{
	if (keycode == RIGHT_ARROW)
		e->depx += 10;
	else if (keycode == LEFT_ARROW)
		e->depx -= 10;
	else if (keycode == UP_ARROW)
		e->depy -= 10;
	else if (keycode == DOWN_ARROW)
		e->depy += 10;
}

int		ft_key_hook(int keycode,t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx_ptr,e->img_ptr);
		// mlx_destroy_window(e->mlx_ptr, e->img_ptr); faut il destroy la fenetre
		exit(0);
	}
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW\
	|| keycode == UP_ARROW || keycode == DOWN_ARROW)
		move(keycode, e);
	else if (keycode == R)
		BOOL(e->r);
	else if (keycode == G)
		BOOL(e->g);
	else if (keycode == B)
		BOOL(e->b);
	else if (keycode == N)
		BOOL(e->neg);
	// if (keycode == R)
	// {
	// 	e->r = 0;
	// 	e->g = 0;
	// 	e->b = 0;
	// }
	else if (keycode == ONE)
		e->fract = 1;
	else if (keycode == TWO)
		e->fract = 2;
	else if (keycode == THREE)
		e->fract = 3;
	else if (keycode == FOUR)
		e->fract = 4;
	else if (keycode == PLUS)
		e->iter += 10;
	else if (keycode == MINUS && e->iter > 10)
		e->iter -= 10;
	// printf("e->iter = %i\n", e->iter);
	new_img(e);
	cross_string(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}

int ft_motion(int x, int y, t_env *e)
{
	if (e->move == 1 && (e->fract == 2 || e->fract == 4)\
	&& x < e->winx && y < e->winy && x > 0 && y > 0)
	{
		e->cn = (1.5 * (float)(x - 1.5 * e->midx) / (e->winx / 2));
		e->ci = (float)(y - e->midy) / (e->winy / 2);
		// printf("x = %f, y = %f\n", e->cn, e->ci);
		new_img(e);
		cross_string(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
	return (0);
}

int mouse_button(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		e->zoom = e->zoom * 2;
		// if (e->cursorx == x && e->cursory == y)
		// {
		// 	e->repx = e->midx;
		// 	e->repy = e->midy; //mammmmmaaaaaaaaa
		// }
		// else
		// {
		// printf("e->repx = %i, e->repy = %i\n", e->repx, e->repy);
		e->repx = e->midx + (e->repx - x);
		e->repy = e->midy + (e->repy - y);
		// }
		// printf("x = %i, y = %i, e->repx = %i, e->repy = %i\n", x, y, e->repx, e->repy);
		e->cursorx = x;
		e->cursory = y;
		e->convx = e->midx / (2.35 / e->zoom);
		e->convy = e->midy / (1.25 / e->zoom);
		new_img(e);
		cross_string(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
	if (button == 5 && e->zoom > 1)
	{
		e->zoom--;
		e->repx = e->midx;
		e->repy = e->midy;
		e->convx = e->midx/ (2.35 / e->zoom);
		e->convy = e->midy/ (1.25 / e->zoom);
		new_img(e);
		cross_string(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
	if (button == 2)
		BOOL(e->move);
	return (0);
}

int main(int argc, char **argv)
{
	t_env e;
	// int fd;

	// fd = open("test", O_RDWR);
	ft_check(&e, argc, argv);
	new_window(&e);
	img(&e);
	e.depx = 0;
	e.depy = 0;
	e.midx = e.winx/2;
	e.midy = e.winy/2;
	e.repx = e.midx;
	e.repy = e.midy;
	e.zoom = 1;
	e.cursorx = -1;
	e.cursory = -1;
	e.convx = e.midx / 2.35;
	e.convy = e.midy / 1.25;
	e.cn = 0;
	e.ci = 0;
	e.r = 0;
	e.g = 0;
	e.b = 0;
	e.neg = 0;
	e.move = 0;
	e.iter = 25;
	cross_string(&e);
	// ft_fill_pixel(100, 100, &e);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	mlx_hook(e.win_ptr, 2, (1 < 0), ft_key_hook, &e);
	mlx_mouse_hook(e.win_ptr, mouse_button, &e);
	mlx_hook(e.win_ptr, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, &e);
	mlx_loop(e.mlx_ptr);
	return(0);
}