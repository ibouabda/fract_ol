/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:42:10 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/17 16:25:58 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void ft_check_frac(t_env *e, char **argv)
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
->burnship\n->burnship_mv\n");
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
			ft_putendl("usage: ./fractol fractale_name [weidth_size]\
[long_size]");
			ft_putendl("Choose one of this resolutions:\n->800 * 450\n\
->1280 * 720\n->1920 * 1080\n->2560 * 1440\n");
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

void mandelbroth(double x, double y, t_env *e)
{
	int k;
	double zi;
	double zn;
	double zi1;
	double zn1;
	double color;
	double sq;

	k = 0;
	zi1 = y;
	zn1 = x;
	color = 255.0f / e->iter;
	while (k < e->iter && ((sq = sqrt(zn1 * zn1 + zi1 *zi1)) <= 2))
	{
		zn = zn1;
		zi = zi1;
		zn1 = zn * zn - zi * zi + x;
		zi1 = 2 * zn * zi + y;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	if (sq >= 2)
		ft_fill_pixel_color(e->x, e->y, (double)((double)k) * color, e);
}

int julia(double x, double y, t_env *e)
{
	int k;
	double zi;
	double zn;
	double zi1;
	double zn1;
	double color;
	double sq;

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
		ft_fill_pixel_color(e->x, e->y, (double)((double)k ) * color, e);
	return (k);
}

void burning_ship(double x, double y, t_env *e)
{
	int k;
	double zi;
	double zn;
	double zi1;
	double zn1;
	double color;
	double sq;

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
		ft_fill_pixel_color(e->x, e->y, (double)((double)k) * color, e);
}

int burning_ship_move(double x, double y, t_env *e)
{
	int k;
	double zi;
	double zn;
	double zi1;
	double zn1;
	double color;
	double sq;

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
		ft_fill_pixel_color(e->x, e->y, (double)((double)k ) * color, e);
	return (k);
}

void cross_string(t_env *e)
{
	double x0;
	double y0;
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
			x0 = (double)(e->x - (e->repx) + e->depx) / (double)e->convx;
			y0 = (double)(e->y - (e->repy) + e->depy) / (double)e->convy;
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

void ft_begin(t_env *e)
{
	e->depx = 0;
	e->depy = 0;
	e->repx = e->midx;
	e->repy = e->midy;
	e->midx = e->winx/2;
	e->midy = e->winy/2;
	e->zoom = 1;
	e->cursorx = -1;
	e->cursory = -1;
	e->convx = e->midx / 2.35;
	e->convy = e->midy / 1.25;
	e->cn = 0;
	e->ci = 0;
	e->r = 0;
	e->g = 0;
	e->b = 0;
	e->neg = 0;
	e->move = 0;
	e->iter = 25;
}

void	move(int keycode, t_env *e)
{
	if (keycode == RIGHT_ARROW)
		e->depx += 10;
	else if (keycode == LEFT_ARROW)
		e->depx -= 10;
	else if (keycode == UP_ARROW)
		e->depy -= 10;
	else if (keycode == DOWN_ARROW)
		e->depy += 10;
	// printf("e->depx = %i, e->depy = %i\n", e->depx, e->depy);
}

// int		ft_key_hook(int keycode,t_env *e)
// {
// 	if (keycode == ESC && e->pause == 1)
// 	{
// 		mlx_destroy_image(e->mlx_ptr,e->img_ptr);
// 		mlx_destroy_image(e->mlx_ptr,e->esc_img_ptr);
// 		// mlx_destroy_window(e->mlx_ptr, e->img_ptr);
// 		exit(0);
// 	}
// 	else if (keycode == ESC && e->pause == 0)
// 	{
// 		e->pause = 1;
// 		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->esc_img_ptr, 0, 0);
// 	}
// 	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW\
// 	|| keycode == UP_ARROW || keycode == DOWN_ARROW)
// 		move(keycode, e);
// 	else if (keycode == R)
// 		BOOL(e->r);
// 	else if (keycode == G)
// 		BOOL(e->g);
// 	else if (keycode == B)
// 		BOOL(e->b);
// 	else if (keycode == N)
// 		BOOL(e->neg);
// 	// if (keycode == R)
// 	// {
// 	// 	e->r = 0;
// 	// 	e->g = 0;
// 	// 	e->b = 0;
// 	// }
// 	else if (keycode == ONE)
// 	{
// 		e->fract = 1;
// 		ft_begin(e);
// 	}
// 	else if (keycode == TWO)
// 	{
// 		e->fract = 2;
// 		ft_begin(e);
// 	}
// 	else if (keycode == THREE)
// 	{
// 		e->fract = 3;
// 		ft_begin(e);
// 	}
// 	else if (keycode == FOUR)
// 	{
// 		e->fract = 4;
// 		ft_begin(e);
// 	}
// 	else if (keycode == PLUS)
// 		e->iter += 5;
// 	else if (keycode == MINUS && e->iter > 10)
// 		e->iter -= 5;
// 	// printf("e->iter = %i\n", e->iter);
// 	// new_img(e);
// 	fractale_creation(e);
// 	return (0);
// }

int ft_motion(int x, int y, t_env *e)
{
	if (e->move == 1 && (e->fract == 2 || e->fract == 4)\
	&& x < e->winx && y < e->winy && x > 0 && y > 0)
	{
		e->cn = (1.5 * (double)(x - 1.5 * e->midx) / (e->winx / 2));
		e->ci = (double)(y - e->midy) / (e->winy / 2);
		// printf("e->cn = %f, e->ci = %f\n", e->cn, e->ci);
		fractale_creation(e);
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
		// e->repxlast = e->repx;
		// e->repylast = e->repy;
		e->repx = e->repx + (e->repx - (x + e->depx));
		e->repy = e->repy + (e->repy - (y + e->depy));
		// }
		// printf("x = %i, y = %i, e->repx = %i, e->repy = %i\n", x, y, e->repx, e->repy);
		e->cursorx = x;
		e->cursory = y;
		e->convx = e->midx / (2.35 / e->zoom);
		e->convy = e->midy / (1.25 / e->zoom);
		fractale_creation(e);
	}
	if (button == 5 && e->zoom > 1)
	{
		e->zoom = 1;
		e->repx = e->midx;
		e->repy = e->midy;
		e->convx = e->midx/ (2.35 / e->zoom);
		e->convy = e->midy/ (1.25 / e->zoom);
		fractale_creation(e);
	}
	if (button == 2)
		BOOL(e->move);
	// printf("e->zoom = %lli e->repx = %lli e->repy = %lli\n", e->zoom, e->repx, e->repy);
	return (0);
}

int main(int argc, char **argv)
{
	t_env e;

	ft_check(&e, argc, argv);
	new_window(&e);
	e.bool = 0;
	img(&e);
	e.esc_img_ptr = e.img_ptr;
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.esc_img_ptr, 0, 0);
	interface(&e);
	img(&e);
	ft_begin(&e);
	mlx_hook(e.win_ptr, 2, (1 < 0), ft_key_hook, &e);
	mlx_mouse_hook(e.win_ptr, mouse_button, &e);
	mlx_hook(e.win_ptr, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, &e);
	mlx_loop(e.mlx_ptr);
	return(0);
}