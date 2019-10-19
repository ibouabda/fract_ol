/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:25:35 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/19 18:48:31 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_key_hook3(int keycode, t_env *e)
{
	if (keycode == RIGHT_ARROW)
		e->depx += 10;
	else if (keycode == LEFT_ARROW)
		e->depx -= 10;
	else if (keycode == UP_ARROW)
		e->depy -= 10;
	else if (keycode == DOWN_ARROW)
		e->depy += 10;
	else if (keycode == R)
		BOOL(e->r);
	else if (keycode == G)
		BOOL(e->g);
	else if (keycode == B)
		BOOL(e->b);
	else if (keycode == N)
		BOOL(e->neg);
	else if (keycode == PLUS)
		e->iter += 5;
	else if (keycode == MINUS && e->iter > 10)
		e->iter -= 5;
	else if (keycode == Z)
		ft_begin(e);
}

int		ft_motion(int x, int y, t_env *e)
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

int		mouse_button(int button, int x, int y, t_env *e)
{
	if (button == 4 && e->zoom < 35184372088832)
	{
		e->zoom = e->zoom * 2;
		e->repx = e->repx + (e->repx - (x + e->depx));
		e->repy = e->repy + (e->repy - (y + e->depy));
		e->convx = e->midx / (2.35 / e->zoom);
		e->convy = e->midy / (1.25 / e->zoom);
		fractale_creation(e);
	}
	if (button == 5 && e->zoom > 1)
	{
		e->zoom = 1;
		e->repx = e->midx;
		e->repy = e->midy;
		e->convx = e->midx / (2.35);
		e->convy = e->midy / (1.25);
		fractale_creation(e);
	}
	// printf("e->zoom = %lli e->repx = %lli e->repy = %lli e->convx = %f e->convy = %f\n", e->zoom, e->repx, e->repy, e->convx, e->convy);
	if (button == 2)
		BOOL(e->move);
	return (0);
}

void	ft_key_hook2(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		e->bool = 0;
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->esc_img_ptr, 0, 0);
		interface(e);
	}
	else if (keycode == ONE)
		e->fract = 1;
	else if (keycode == TWO)
		e->fract = 2;
	else if (keycode == THREE)
		e->fract = 3;
	else if (keycode == FOUR)
		e->fract = 4;
	if (keycode == ONE || keycode == TWO || keycode == THREE || keycode == FOUR)
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
		ft_key_hook3(keycode, e);
		if (e->bool == 1)
			fractale_creation(e);
	}
	return (0);
}
