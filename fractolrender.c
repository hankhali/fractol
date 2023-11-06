/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolrender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:55:52 by hankhali          #+#    #+#             */
/*   Updated: 2023/10/30 21:13:51 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window,
		fractol->img.img_ptr,
		0,
		0);
}

int	resize_handler(int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (fractol->is_locked)
	{
		return (1);
	}
	return (0);
}
