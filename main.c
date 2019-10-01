/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:42:10 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/01 19:49:25 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check(t_env *e, int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putendl("usage: ./fractol fractale_name [400 <= weidth_size <= 2560]\
[800 <= long_size <= 1440]");
		ft_putendl("choose one of this fractals:\n->mandelbroth\n->julia");
		exit(1);
	}
	if (ft_strequ(argv[1], "mandelbroth"))
		e->fract = 1;
	else if (ft_strequ(argv[1], "julia"))
		e->fract = 2;
	else
	{
		ft_putendl("choose one of this fractals:\n->mandelbroth\n->julia");
	}
	e->winx = ft_atoi(argv[2]);
	e->winy = ft_atoi(argv[3]);
	if (e->winx < 400 || e->winy < 800 || e->winx > 2560 || e->winy > 1440)
	{
		ft_putendl(USAGE);
		exit(1);
	}
}

void mandelbroth(float x, float y, t_env *e)
{
	int k;
	float zi;
	float zn;
	float zi1;
	float zn1;

	k = 0;
	zi1 = y;
	zn1 = x;
	while (k < 15 && zi1 < 2 && zn1 < 2 && sqrt(zn1 * zn1 + zi1 *zi1))
	{
		zn = zn1;
		zi = zi1;
		zn1 = zn * zn - zi * zi + x;
		zi1 = 2 * zn * zi + y;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	if (zn1 >= 2 || zi1 >=2 || sqrt(zn1 * zn1 + zi1 * zi1) >= 2)
		ft_fill_pixel(e->x, e->y, e);
}

void julia(float x, float y, t_env *e)
{
	int k;
	float zi;
	float zn;
	float zi1;
	float zn1;

	k = 0;
	zi1 = y;
	zn1 = x;
	while (k < 15 && zi1 < 2 && zn1 < 2 && sqrt(zn1 * zn1 + zi1 *zi1))
	{
		zn = zn1;
		zi = zi1;
		zn1 = zn * zn - zi * zi + e->cn;
		zi1 = 2 * zn * zi + e->ci;
		k++;
	}
	// printf("zn1 = %f, zi1 = %f\n", zn1, zi1);
	if (zn1 >= 2 || zi1 >=2 || sqrt(zn1 * zn1 + zi1 * zi1) >= 2)
		ft_fill_pixel(e->x, e->y, e);
}

void cross_string(t_env *e)
{
	float x0;
	float y0;

	e->y = 0;
	while (e->y < e->winy)
	{
		e->x = 0;
		while (e->x < e->winx)
		{
			// if (e->y < 50)
			// 	dprintf(fd, "x0 = %f, y0 = %f\n", x0, y0);
			x0 = (float)(e->x - e->midx) / (float)e->convx;
			y0 = (float)(e->y - e->midy) / (float)e->convy;
			if (e->fract == 1)
				mandelbroth(x0, y0, e);
			else if (e->fract == 2)
				julia(x0, y0, e);
			e->x++;
		}
		e->y++;
	}
}

int		ft_key_hook(int keycode,t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx_ptr,e->img_ptr);
		exit(0);
	}
	if (e->fract == 2)
	{
		if (keycode == W)
			e->ci += 0.03;
		if (keycode == S)
			e->ci -= 0.03;
		if (keycode == A)
			e->cn -= 0.03;
		if (keycode == D)
			e->cn += 0.03;
	}
	if (keycode == ONE)
	{
		e->fract = 1;
	}
	if (keycode == TWO)
	{
		e->fract = 2;
	}
	if (keycode == 1)
	{
		if (e->fract == 1)
			e->fract--;
		if (e->fract == 0)
			e->fract++;
	}
	new_img(e);
	cross_string(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}

// int ft_motion(int x, int y, t_env *e)
// {
// 	e->cn = x/100;
// 	e->ci = y/100;
// 	new_img(e);
// 	cross_string(e);
// 	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_env e;
	int fd;

	fd = open("test", O_RDWR);
	ft_check(&e, argc, argv);
	new_window(&e);
	img(&e);
	e.midx = e.winx/2;
	e.midy = e.winy/2;
	e.convx = e.midx / 2.35;
	e.convy = e.midy / 1.25;
	e.cn = 0;
	e.ci = 0;
	e.fract = 1;
	cross_string(&e);
	// ft_fill_pixel(100, 100, &e);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	mlx_hook(e.win_ptr, 2, (1 < 0), ft_key_hook, &e);
	// mlx_hook(e.win_ptr, 2, (1L << 8), ft_motion, &e);
	mlx_loop(e.mlx_ptr);
	return(0);
}