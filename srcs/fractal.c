/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:53:20 by idris             #+#    #+#             */
/*   Updated: 2019/10/17 19:02:05 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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
	if (sq >= 2)
		ft_fill_pixel_color(e->x, e->y, (double)((double)k ) * color, e);
	return (k);
}