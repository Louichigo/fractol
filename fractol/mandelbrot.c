/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:53:01 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/19 16:53:44 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_data img, double x, double y)
{
	double zr = 0;
	double zi = 0;
	double i = 0;
	double cr = (x / ZOOM + XMIN);
	double ci = (y / ZOOM + YMIN);
	while ((zr * zr) + (zi * zi) < 4 && i < IMAX)
	{
	 double temp = zr;
	 zr = (temp * temp) - (zi * zi) + cr;
	 zi = (2 * zi * temp) + ci;
	 i++;
	}
	if (i == IMAX)
		my_mlx_pixel_put(&img, x, y, 0xFF513D);
	else
		my_mlx_pixel_put(&img, x, y, (0xFF513D * i));
}

void	mandelco(t_data img)
{
	double x = 0;
	double y = 0;
	while (x < LARGEUR)
	{
		while (y < HAUTEUR)
		{
			ft_mandelbrot(img, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}