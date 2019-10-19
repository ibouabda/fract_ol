/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:53:20 by idris             #+#    #+#             */
/*   Updated: 2019/10/19 18:50:01 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	mandelbrot(double x, double y, t_env *e)
{
	int		k;
	double	zi;
	double	zn;
	double	zi1;
	double	zn1;

	k = 0;
	zi1 = y;
	zn1 = x;
	while (k < e->iter && (sqrt(zn1 * zn1 + zi1 * zi1)) <= 2)
	{
		zn = zn1;
		zi = zi1;
		zn1 = zn * zn - zi * zi + x;
		zi1 = 2 * zn * zi + y;
		k++;
	}
	if ((sqrt(zn1 * zn1 + zi1 * zi1)) >= 2)
		ft_fill_pixel_color(e->x, e->y, k * (255.0f / e->iter), e);
}

void	julia(double x, double y, t_env *e)
{
	int		k;
	double	zi;
	double	zn;
	double	zi1;
	double	zn1;

	k = 0;
	zi1 = y;
	zn1 = x;
	while (k < e->iter && (sqrt(zn1 * zn1 + zi1 * zi1)) <= 2)
	{
		zn = zn1;
		zi = zi1;
		zn1 = zn * zn - zi * zi + e->cn;
		zi1 = 2 * zn * zi + e->ci;
		k++;
	}
	if ((sqrt(zn1 * zn1 + zi1 * zi1)) >= 2)
		ft_fill_pixel_color(e->x, e->y, k * (255.0f / e->iter), e);
}

void	burning_ship(double x, double y, t_env *e)
{
	int		k;
	double	zi;
	double	zn;
	double	zi1;
	double	zn1;

	k = 0;
	zi1 = y;
	zn1 = x;
	while (k < e->iter && (sqrt(zn1 * zn1 + zi1 * zi1)) <= 2)
	{
		zn = ABS(zn1);
		zi = ABS(zi1);
		zn1 = zn * zn - zi * zi + x;
		zi1 = 2 * zn * zi + y;
		k++;
	}
	if ((sqrt(zn1 * zn1 + zi1 * zi1)) >= 2)
		ft_fill_pixel_color(e->x, e->y, k * (255.0f / e->iter), e);
}

void	burning_ship_move(double x, double y, t_env *e)
{
	int		k;
	double	zi;
	double	zn;
	double	zi1;
	double	zn1;

	k = 0;
	zi1 = y;
	zn1 = x;
	while (k < e->iter && (sqrt(zn1 * zn1 + zi1 * zi1)) <= 2)
	{
		zn = ABS(zn1);
		zi = ABS(zi1);
		zn1 = zn * zn - zi * zi + e->cn;
		zi1 = 2 * zn * zi + e->ci;
		k++;
	}
	if ((sqrt(zn1 * zn1 + zi1 * zi1)) >= 2)
		ft_fill_pixel_color(e->x, e->y, k * (255.0f / e->iter), e);
}

void	fractale_creation(t_env *e)
{
	new_img(e);
	cross_string(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	interface_in_game(e);
}
