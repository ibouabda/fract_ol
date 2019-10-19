/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:25:35 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/19 15:56:08 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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
}

int ft_motion(int x, int y, t_env *e)
{
	if (e->move == 1 && (e->fract == 2 || e->fract == 4)\
	&& x < e->winx && y < e->winy && x > 0 && y > 0 && e->bool == 1)
	{
		e->cn = (1.5 * (double)(x - 1.5 * e->midx) / (e->winx / 2));
		e->ci = (double)(y - e->midy) / (e->winy / 2);
		fractale_creation(e);
	}
	return (0);
}

void unzoom(t_env *e, int x, int y)
{
	long long int zoom;

	zoom = 1;
	e->repx = e->midx;
	e->repy = e->midy;
	while (zoom < e->zoom)
	{
		e->repx = e->repx + (e->repx - (x + e->depx));
		e->repy = e->repy + (e->repy - (y + e->depy));
		zoom = zoom * 2;
	}
}

int mouse_button(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;

	if (button == 4)
	{
		e->zoom = e->zoom * 2;
		e->envlx = (2.35 / e->zoom) + (double)(x / (double)e->convx);
		e->envly = (1.25 / e->zoom) + (double)(y / (double)e->convy);
		e->convx = e->midx / e->envlx;
		e->convy = e->midy / e->envly;
		// e->repx = (double)(x / (double)e->convx);
		// e->repy = (double)(y / (double)e->convy);
		fractale_creation(e);
	}
	if (button == 5 && e->zoom > 1)
	{
		// e->zoom = e->zoom / 2;
		// unzoom(e, x, y);
		// // unzoom(e, e->cursorx, e->cursory);
		// e->convx = e->midx/ (2.35 / e->zoom);
		// e->convy = e->midy/ (1.25 / e->zoom);
		// fractale_creation(e);
	}
	printf("e->zoom = %lli, e->envlx = %f, e->repy = %f\n", e->zoom, e->repx, e->repy);
	printf("e->zoom = %lli, e->repx = %f, e->repy = %f\n", e->zoom, e->repx, e->repy);
	if (button == 2)
		BOOL(e->move);
	return (0);
}

// void unzoom(t_env *e, int x, int y)
// {
// 	long long int zoom;

// 	zoom = 1;
// 	e->repx = e->midx;
// 	e->repy = e->midy;
// 	while (zoom < e->zoom)
// 	{
// 		e->repx = e->repx + (e->repx - (x + e->depx));
// 		e->repy = e->repy + (e->repy - (y + e->depy));
// 		zoom = zoom * 2;
// 	}
// }

// int mouse_button(int button, int x, int y, t_env *e)
// {
// 	(void)x;
// 	(void)y;

// 	if (button == 4)
// 	{
// 		e->zoom = e->zoom * 2;
// 		e->repx = e->repx + (e->repx - (x + e->depx));
// 		e->repy = e->repy + (e->repy - (y + e->depy));
// 		e->convx = e->midx / (2.35 / e->zoom);
// 		e->convy = e->midy / (1.25 / e->zoom);
// 		fractale_creation(e);
// 	}
// 	if (button == 5 && e->zoom > 1)
// 	{
// 		e->zoom = e->zoom / 2;
// 		unzoom(e, e->cursorx, e->cursory);
// 		e->convx = e->midx/ (2.35 / e->zoom);
// 		e->convy = e->midy/ (1.25 / e->zoom);
// 		fractale_creation(e);
// 	}
// 	// printf("e->zoom = %lli, e->repx = %lli, e->repy = %lli\n", e->zoom, e->repx, e->repy);
// 	if (button == 2)
// 		BOOL(e->move);
// 	return (0);
// }

void	ft_key_hook2(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		e->bool = 0;
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->esc_img_ptr, 0, 0);
		interface(e);
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
	else if (keycode == ONE)
	{
		e->fract = 1;
		ft_begin(e);
	}
	else if (keycode == TWO)
	{
		e->fract = 2;
		ft_begin(e);
	}
	else if (keycode == THREE)
	{
		e->fract = 3;
		ft_begin(e);
	}
	else if (keycode == FOUR)
	{
		e->fract = 4;
		ft_begin(e);
	}
	else if (keycode == PLUS)
		e->iter += 5;
	else if (keycode == MINUS && e->iter > 10)
		e->iter -= 5;
	else if (keycode == Z)
		ft_begin(e);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (e->bool == 0)
	{
		e->bool = keycode == ENTER ? 1 : 0;
		if (keycode == ESC)
		{
			mlx_destroy_image(e->mlx_ptr, e->esc_img_ptr);
			mlx_destroy_image(e->mlx_ptr, e->img_ptr);
			mlx_destroy_window(e->mlx_ptr, e->win_ptr);
			exit(0);
		}
	}
	if (e->bool == 1)
	{
		ft_key_hook2(keycode, e);
		if (e->bool == 1)
			fractale_creation(e);
	}
	// printf("ok\n");
	return (0);
}