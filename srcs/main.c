/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:42:10 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/19 15:45:39 by ibouabda         ###   ########.fr       */
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
->burnship\n->burnship_mv");
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
		if (!((e->winx == 800 && e->winy == 450) || (e->winx == 1280 && \
		e->winy == 720) || (e->winx == 1920 && e->winy == 1080) || \
		(e->winx == 2560 && e->winy == 1440)))
		{
			ft_putusage(1);
			exit(1);
		}
	}
	else
	{
		ft_putusage(0);
		exit(1);
	}
	ft_check_frac(e, argv);
}

void cross_string(t_env *e)
{
	double x0;
	double y0;

	e->y = 0;
	while (e->y < e->winy)
	{
		e->x = 0;
		while (e->x < e->winx)
		{
			x0 = ((double)(e->x + e->depx) / (double)e->convx) - e->envlx;
			y0 = ((double)(e->y + e->depy) / (double)e->convy) - e->envly;
			if (e->x == 0 && e->y == 0)
			{
				printf("x0 = %f, y0 = %f\n", x0, y0);
			}
			if (e->fract == 1)
				mandelbroth(x0, y0, e);
			else if (e->fract == 2)
				julia(x0, y0, e);
			else if (e->fract == 3)
				burning_ship(x0, y0, e);
			else if (e->fract == 4)
				burning_ship_move(x0, y0, e);
			e->x++;
		}
		e->y++;
	}
}

void ft_begin(t_env *e)
{
	e->depx = 0;
	e->depy = 0;
	e->midx = e->winx / 2;
	e->midy = e->winy / 2;
	e->repx = 0;
	e->repy = 0;
	e->zoom = 1;
	e->envlx = 2.35;
	e->envly = 1.25;
	e->convx = e->midx / 2.35;
	e->convy = e->midy / 1.25;
	e->cn = 0;
	e->ci = 0;
	e->r = 0;
	e->g = 0;
	e->b = 0;
	e->neg = 0;
	e->move = 1;
	e->iter = 25;
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