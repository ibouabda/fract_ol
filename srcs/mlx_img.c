/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/10/20 11:59:14 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_define_color(int pos, int color, t_env *e)
{
	if (e->b == 0 && e->r == 0 && e->g == 0 && e->neg == 0)
	{
		e->img_string[pos] = (char)(color);
		e->img_string[pos + 1] = (char)(color);
		e->img_string[pos + 2] = (char)(color);
	}
	else if (e->b == 0 && e->r == 0 && e->g == 0 && e->neg == 1)
	{
		e->img_string[pos] = 255 - (char)(color);
		e->img_string[pos + 1] = 255 - (char)(color);
		e->img_string[pos + 2] = 255 - (char)(color);
	}
	else if (e->neg == 0)
	{
		e->img_string[pos] = (char)((e->b * color));
		e->img_string[pos + 1] = (char)(e->g * color);
		e->img_string[pos + 2] = (char)(e->r * color);
	}
	else if (e->neg == 1)
	{
		e->img_string[pos] = (char)(255 - (e->b * color));
		e->img_string[pos + 1] = (char)(255 - (e->g * color));
		e->img_string[pos + 2] = (char)(255 - (e->r * color));
	}
}

void	ft_fill_pixel_color(int x, int y, int color, t_env *e)
{
	int	pos;

	pos = y * e->winx * 4 + x * 4;
	ft_define_color(pos, color, e);
}

void	new_window(t_env *e)
{
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, e->winx, e->winy, "fract_ol");
}

void	img(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->img_ptr = mlx_new_image(e->mlx_ptr, e->winx, e->winy);
	e->img_string = mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
}

void	new_img(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, e->winx, e->winy);
	e->img_string = mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
}
