/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:37:34 by hankhali          #+#    #+#             */
/*   Updated: 2023/10/30 21:20:53 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "fractol.h"

double	map(double uns_num, t_mappingrange range)
{
	return ((uns_num - range.o_min) * (range.n_max - range.n_min) / (range.o_max
			- range.o_min) + range.n_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
