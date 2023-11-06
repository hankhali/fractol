/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:00:43 by hankhali          #+#    #+#             */
/*   Updated: 2023/10/16 17:24:06 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractol.h"

extern int	key_handler(int keysym, t_fractol *fractal);
extern int	mouse_handler(int button, int x, int y, t_fractol *fractol);
extern int	close_handler(t_fractol *fractal);
extern int	julia_track(int x, int y, t_fractol *fractal);

#endif