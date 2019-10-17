/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:08:26 by idris             #+#    #+#             */
/*   Updated: 2019/10/17 14:49:15 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void interface_in_game(t_env *e)
{
	char *striter;
	char *todel;

	striter = ft_itoa(e->iter);
	todel = ft_strjoin("Iter : ", striter); //memory "Iter:" ???"
	if (e->neg == 1)
	{
		mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 5, 0x808080, "N");
	}

	if (e->r == 1)
	{
		mlx_string_put(e->mlx_ptr, e->win_ptr, 15, 5, 0xFF0000, "R");
	}

	if (e->g == 1)
	{
		mlx_string_put(e->mlx_ptr, e->win_ptr, 25, 5, 0x008000, "G");
	}

	if (e->b == 1)
	{
		mlx_string_put(e->mlx_ptr, e->win_ptr, 35, 5, 0x0000FF, "B");
	}
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx - 100, 5, 0x808080, todel);
	ft_strdel(&striter);
	ft_strdel(&todel);
}

void	interface(t_env *e)
{
	int a;

	a = e->winy / 20;
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(TITLE) * 5,\
	e->winy / 4 - a, 0xffffff, TITLE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(BEGIN) * 5,\
	e->winy / 4, 0xffffff, BEGIN);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(MOVE) * 5,\
	e->winy / 4 + a * 2, 0xffffff, MOVE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ZOOM) * 5,\
	e->winy / 4 + a * 3, 0xffffff, ZOOM);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(COLORS) * 5,\
	e->winy / 4 + a * 4, 0xffffff, COLORS);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(FRACTAL) * 5,\
	e->winy / 4 + a * 5, 0xffffff, FRACTAL);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(PAUSE) * 5,\
	e->winy / 4 + a * 6, 0xffffff, PAUSE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(RESET) * 5,\
	e->winy / 4 + a * 7, 0xffffff, RESET);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(QUIT) * 5,\
	e->winy / 4 + a * 8, 0xffffff, QUIT);
}