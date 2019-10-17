/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:25:35 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/17 14:21:33 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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
		{
			fractale_creation(e);
		}
	}
	return (0);
}