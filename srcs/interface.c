/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:08:26 by idris             #+#    #+#             */
/*   Updated: 2019/10/17 10:35:06 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	interface_in_game(t_env *e)
{

    if (e->r == 1)
    {
        mlx_string_put(e->mlx_ptr, e->win_ptr, 5,\
        5, 0xFF0000, "R");
    }
    if (e->g == 1)
    {
        mlx_string_put(e->mlx_ptr, e->win_ptr, 10,\
        10, 0x008000, "G");
    }
    if (e->b == 1)
    {
        mlx_string_put(e->mlx_ptr, e->win_ptr, 15,\
        15, 0x0000FF, "B");
    }
}

// void	interface_in_game(t_env *e)
// {
// 	int a;

// 	a = e->winy / 23;
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(FDF) * 5,\
// 	e->winy / 2.5 - a, 0xD50097, FDF);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(BEGIN) * 5,\
// 	e->winy / 2.5, 0x0000FF, BEGIN);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(MOVE) * 5,\
// 	e->winy / 2.5 + a * 2, 0x0000FF, MOVE);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ANGLE) * 5,\
// 	e->winy / 2.5 + a * 3, 0xD50097, ANGLE);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ZOOM) * 5,\
// 	e->winy / 2.5 + a * 4, 0x0000FF, ZOOM);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5,\
// 	e->winy / 2.5 + a * 5, 0xD50097, INC);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5,\
// 	e->winy / 2.5 + a * 6, 0x0000FF, PROJ);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(PAUSE) * 5,\
// 	e->winy / 2.5 + a * 7, 0xD50097, PAUSE);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(RESET) * 5,\
// 	e->winy / 2.5 + a * 8, 0x0000FF, RESET);
// 	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(QUIT) * 5,\
// 	e->winy / 2.5 + a * 9, 0xD50097, QUIT);
// }