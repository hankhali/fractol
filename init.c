/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:22:51 by hankhali          #+#    #+#             */
/*   Updated: 2023/10/30 21:27:27 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "fractol.h"

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_defintion = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	events_init(t_fractol *fractolt_fractol)
{
	mlx_key_hook(fractolt_fractol->mlx_window, key_handler, fractolt_fractol);
	mlx_mouse_hook(fractolt_fractol->mlx_window, mouse_handler,
		fractolt_fractol);
	mlx_hook(fractolt_fractol->mlx_window, 17, 1L << 17, close_handler,
		fractolt_fractol);
	mlx_hook(fractolt_fractol->mlx_window, 6, 1L << 6, julia_track,
		fractolt_fractol);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
